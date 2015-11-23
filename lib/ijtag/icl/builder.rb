require 'ijtag/icl/processor'
require 'ijtag/icl/numeric_expression_processor'
module IJTAG
  module ICL
    class BuildError < AST::Error
    end

    class Builder < Processor
      include NumericExpressionProcessor

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
        apply_deferred_operations
        apply_deferred_connections
        top_level
      end

      def on_instance_def(node)
        name, module_name, *items = *node.children
        module_def = network_def.modules[module_name.value]
        fail BuildError.new("A module defintion for #{module_name.value} could not be found", node) unless module_def
        model = current_module.add_block(:Module, name.value, icl: module_def, module_name: module_name.value, network: top_level)
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
            else
              fail "Don't know how to model #{item.type} in an instance def"
            end
          end
          process_all(module_def.children)
        end
        # Finally hook up the implied connections to the new modules parent now that it has
        # been full instantiated
        current_module.send(:connect_module, model)
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
        if type == :ScanOutPort
          size = c.size || 1
        else
          size = c.size
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
            node = network.path_to_node(p)
            if node.is_a?(Origen::Models::Mux)
              node = node.output
            end
            mux.option o[0], node
          end
        end
      end

      private

      def defer(&block)
        @deferred_operations ||= []
        @deferred_operations << block
      end

      def apply_deferred_operations
        (@deferred_operations || []).each do |op|
          op.call
        end
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
    end
  end
end
