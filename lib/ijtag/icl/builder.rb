# rubocop:disable Style/MethodName: Use snake_case for method names.
# rubocop:disable Style/Lambda: Use the lambda method for multi-line lambdas.
require 'ijtag/icl/processor'
require 'ijtag/icl/expression_processor'
module IJTAG
  module ICL
    class BuildError < AST::Error
    end

    class Builder < Processor
      include ExpressionProcessor

      # Returns the built network object after the processor has run
      attr_reader :top_level
      attr_reader :network_def

      alias_method :network, :top_level

      def initialize(network_def)
        @network_def = network_def
      end

      def on_module_def(node, params = {})
        name, *items = *node
        model = Module.new(icl: node, path: :hidden, top_level: true)
        @top_level = model
        define_module(model) do
          params.each do |k, v|
            k = k.to_s
            parameters[k] ||= v
          end
          process_all(items)
        end
        apply_deferred_connections
        apply_deferred_operations
        top_level
      end

      def on_instance_def(node)
        name, module_name, *items = *node.children
        module_def = network_def.modules[module_name.value]
        fail BuildError.new("A module defintion for #{module_name.value} could not be found", node) unless module_def
        model = current_module.add_block(:Module, name.value, icl: module_def, module_name: module_name.value, network: top_level)
        # Connect up the default connections at the end once fully instantiated
        defer { connect_module(model) }
        define_module(model) do
          process_all(items).each do |item|
            case item.type
            when :inputPort_connection
              a, b = *item
              a = Connection.new(a).add_root(current_module.path).to_s
              if b.numeric?
                defer_connection(a, b.path)
              else
                b = Connection.new(b).add_root(current_module.parent.path).to_s
                defer_connection a, -> do
                  node = network.path_to_node(b)
                  if node.is_a?(Origen::Models::Mux)
                    node.output
                  else
                    node
                  end
                end
              end
            when :parameter_def
              # Do nothing, already applied
            when :allowBroadcast_def
              model.instance_variable_set('@allow_broadcast', item.to_a[0])
            else
              fail "Don't know how to model #{item.type} in an instance def"
            end
          end
          process_all(module_def.children)
        end
      end

      def on_range(node)
        first, last = *process_all(node)
        first..last
      end

      def on_parameter_def(node)
        name, val = *process_all(node)
        parameters[name] ||= val
        node
      end

      def on_parameter_ref(node)
        parameters[node.value]
      end

      def on_hier_port(node)
        process_all(node).join('.')
      end

      def on_SCALAR_ID(node)
        node.children.first
      end

      def on_vector_id(node)
        nodes = process_all(node)
        Connection.new(nodes[0], index: nodes[1])
      end

      def on_signal(node)
        nodes = process_all(node)
        if nodes.size > 1
          fail BuildError.new('Signal definition expects only one child', node)
        end
        Connection.new(nodes[0], type: node.type)
      end
      alias_method :on_scan_signal, :on_signal
      alias_method :on_data_signal, :on_signal
      alias_method :on_reset_signal, :on_signal

      def on_port_def(node)
        name, *items = *process_all(node)
        c = Connection.new(name)
        type = node.type.to_s.sub('_def', '').camelize.to_sym
        if type == :DataInPort || type == :DataOutPort
          size = c.size
        else
          size = 1
        end
        port = current_module.add_port(c.path, size: size, type: type)

        items.each do |item|
          case item.type
          when :source
            item.to_a[0].add_root(port.parent.path).each do |connection|
              # ICL doesn't provide the detail about whether a scan register connection is to a scan register's
              # update stage or not, instead it is implied based on the type of the signal - data_signals are to
              # the update path, scan_signals are not.
              defer_connection port.path, -> do
                node = network.path_to_node(connection.path)
                if connection.type == :scan_signal
                  if node.is_a?(Origen::Models::ScanRegister)
                    node.so
                  elsif node.is_a?(Origen::Models::Mux)
                    node.output
                  else
                    node
                  end
                else
                  node
                end
              end
            end
          else
            fail BuildError.new("#{item.type} does not have a build rule yet in a port def", node)
          end
        end
      end
      alias_method :on_scanInPort_def, :on_port_def
      alias_method :on_scanOutPort_def, :on_port_def
      alias_method :on_shiftEnPort_def, :on_port_def
      alias_method :on_captureEnPort_def, :on_port_def
      alias_method :on_updateEnPort_def, :on_port_def
      alias_method :on_selectPort_def, :on_port_def
      alias_method :on_resetPort_def, :on_port_def
      alias_method :on_tckPort_def, :on_port_def
      alias_method :on_dataInPort_def, :on_port_def
      alias_method :on_dataOutPort_def, :on_port_def
      alias_method :on_toCaptureEnPort_def, :on_port_def
      alias_method :on_toShiftEnPort_def, :on_port_def
      alias_method :on_toUpdateEnPort_def, :on_port_def
      alias_method :on_toSelectPort_def, :on_port_def
      alias_method :on_toResetPort_def, :on_port_def
      alias_method :on_toTckPort_def, :on_port_def

      def on_alias_def(node)
        current_module.aliases << node
      end

      def on_enum_def(node)
        current_module.enumerations << node
      end

      def on_scanInterface_def(node)
        name, *items = *process_all(node)
        int = current_module.add_scan_interface(name)
        items.each do |item|
          case item.type
          when :scanInterfacePort_def
            int.add_port item.to_a[0]
          else
            fail BuildError.new("#{item.type} does not have a build rule yet in a ScanInterface def", node)
          end
        end
      end

      def on_scanRegister_def(node)
        name, *items = *process_all(node)
        c = Connection.new(name)
        elements = { attributes: [] }
        items.each do |item|
          if item.type == :attribute_def
            elements[:attributes] << item
          elsif elements[item.type]
            fail BuildError.new("A ScanRegister definition can declare only one #{item.type.to_s.camelize}", node)
          else
            elements[item.type] = item
          end
        end
        unless elements[:scanInSource]
          fail BuildError.new('A ScanRegister definition must declare a ScanInSource', node)
        end
        if elements[:resetValue]
          reset = elements[:resetValue].to_a[0]
        else
          reset = 0
        end
        reg = current_module.add_block('Origen::Models::ScanRegister', c.path, size: c.size || 1, reset: reset)
        defer { connect_sr(reg) }
        elements[:scanInSource].to_a[0].add_root(reg.parent.path).each do |connection|
          defer_connection reg.si, -> do
            if connection.numeric?
              obj = connection.path
            else
              obj = eval("top_level.#{connection}")
            end
            if obj.is_a?(Origen::Models::Mux)
              obj.output
            elsif obj.is_a?(Origen::Models::ScanRegister)
              obj.so
            else
              obj
            end
          end
        end
        if elements[:captureSource]
          source = elements[:captureSource].to_a[0]
          if source.numeric?
            reg.c.connect_to(source.path)
          else
            source.add_root(reg.parent.path).each do |connection|
              reg.c.connect_to(connection.to_s)
            end
          end
        end
      end

      def on_scanMux_def(node)
        name, selected_by, *options = *process_all(node)
        c = Connection.new(name)
        mux = current_module.add_block('Origen::Models::Mux', c.path)
        selected_by.add_root(mux.parent.path).each do |connection|
          mux.select_by connection.to_s
        end
        options.each do |option|
          o = option.to_a
          p = o[1].add_root(current_module.path).to_s
          defer do
            n = network.path_to_node(p)
            if n.is_a?(Origen::Models::ScanRegister)
              n = n.so
            elsif n.is_a?(Origen::Models::Mux)
              n = n.output
            elsif n.is_a?(Origen::Registers::BitCollection)
              # If this is a scan connection to bit 0 of a scan register
              if o[1].type == :scan_signal
                if n.parent.try(:parent).is_a?(Origen::Models::ScanRegister)
                  n = n.parent.parent.so
                end
              end
            end
            mux.option o[0], n
          end
        end
      end

      def on_logicSignal_def(node)
        name, *items = *process_all(node)
        port = current_module.add_port(name, size: 1)
        @logic_processor ||= LogicProcessor.new
        logic = node.to_a[1]
        port.connect_to do
          @logic_processor.evaluate(logic, port.parent)
        end
      end

      private

      def defer(&block)
        @deferred_operations ||= []
        @deferred_operations << block
      end

      def apply_deferred_operations
        (@deferred_operations || []).each(&:call)
      end

      def apply_deferred_connections
        (@deferred_connections || []).each do |a, b|
          a = a.call if a.is_a?(Proc)
          b = b.call if b.is_a?(Proc)
          a = eval("top_level.#{a}") if a.is_a?(String)
          a.connect_to b
        end
      end

      def defer_connection(a, b)
        @deferred_connections ||= []
        @deferred_connections << [a, b]
      end

      def define_module(model)
        modules.push model
        _parameters.push({})
        yield
        modules.pop
        _parameters.pop
      end

      def modules
        @modules ||= []
      end

      def _parameters
        @_parameters ||= []
      end

      def current_module
        modules.last
      end

      def parameters
        _parameters.last
      end

      def connect_module(mod)
        parent = mod.parent
        unless mod.client_interfaces.empty? || parent.client_interfaces.empty?
          if mod.client_interfaces[0].ue.connections.empty?
            mod.client_interfaces[0].ue.connect_to do
              bitwise_and(mod.client_interfaces[0].sel.data, parent.client_interfaces[0].ue.data)
            end
          end
          if mod.client_interfaces[0].se.connections.empty?
            mod.client_interfaces[0].se.connect_to do
              bitwise_and(mod.client_interfaces[0].sel.data, parent.client_interfaces[0].se.data)
            end
          end
          if mod.client_interfaces[0].ce.connections.empty?
            mod.client_interfaces[0].ce.connect_to do
              bitwise_and(mod.client_interfaces[0].sel.data, parent.client_interfaces[0].ce.data)
            end
          end
          # If no select signal connection is explicitly defined, consider a module
          # selected whenever its scan out is visible at the top-level
          if mod.client_interfaces[0].sel.connections.empty?
            mod.client_interfaces[0].sel.connect_to do
              # If a module can be in a broadcast configuration, then it could be enabled while
              # its SO is not visible, so in that case we can't infer selection by visibility
              if mod.can_be_in_broadcast_config?
                parent.client_interfaces[0].sel
              else
                mod.so_visible? ? 1 : 0
              end
            end
          end
        end
      end

      # Cheating a bit here, but easier to treat undefined as 0 these behavioral models rather than
      # require all signals to be explicitly setup
      def bitwise_and(a, b)
        a = 0 if a == undefined
        b = 0 if b == undefined
        a & b
      end

      def connect_sr(sr)
        unless sr.parent.client_interfaces.empty?
          sr.ue.connect_to sr.parent.client_interfaces[0].ue
          sr.se.connect_to sr.parent.client_interfaces[0].se
          sr.ce.connect_to sr.parent.client_interfaces[0].ce
        end
      end
    end
  end
end
# rubocop:enable Style/MethodName: Use snake_case for method names.
# rubocop:enable Style/Lambda: Use the lambda method for multi-line lambdas.
