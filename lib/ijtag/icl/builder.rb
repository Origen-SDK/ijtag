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
            unless v.is_a?(AST::Node)
              if v.is_a?(String)
                v = AST::Node.new :STRING, [v]
              else
                v = AST::Node.new :POS_INT, [v]
              end
            end
            parameters[k] ||= v
          end
          process_all(items)
        end
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
              netlist.add_net(to_vector(b, path: current_module.parent.path), to_vector(a, path: current_module.path), :instance_inputPort)
            when :parameter_def
              # Do nothing, already applied
            else
              fail "Don't know how to model #{item.type} in an instance def"
            end
          end
          process_all(module_def.children)
        end
      end

      def on_parameter_def(node)
        name, val = *process_all(node)
        parameters[name.value] ||= val
        node
      end

      def on_parameter_ref(node)
        parameters[node.value]
      end

      def on_port_def(node)
        name, *items = *process_all(node)
        name_and_size = name_and_size_from(name)
        type = node.type.to_s.sub('_def', '').camelize.to_sym
        port = current_module.add_block(:Port, name_and_size[0], size: name_and_size[1], icl: node, network: top_level, type: type)
        items.each do |item|
          case item.type
          when :source
            netlist.add_net(to_vector(item.to_a[0], path: port.parent.path), to_vector(port.path), "#{type}_source".to_sym)
          else
            fail "Don't know how to model #{item.type} in a port def"
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

      def on_alias_def(node)
        current_module.aliases << node
      end

      def on_enum_def(node)
        current_module.enumerations << node
      end

      def on_scanInterface_def(node)
        name, *items = *process_all(node)
        name_and_size = name_and_size_from(name)
        current_module.scan_interfaces[name_and_size[0]] = node
      end

      def on_scanRegister_def(node)
        name, *items = *process_all(node)
        name_and_size = name_and_size_from(name)
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
        reg = current_module.add_block(:ScanRegister, name_and_size[0], size: name_and_size[1], icl: node, network: top_level)
        netlist.add_net(to_vector(elements[:scanInSource].to_a[0],  path: reg.parent.path), to_vector(reg.path), :scanInSource)
        netlist.add_net(to_vector(elements[:captureSource].to_a[0], path: reg.parent.path), to_vector(reg.path), :captureSource) if elements[:captureSource]
      end

      def on_scanMux_def(node)
        name, selected_by, *selections = *process_all(node)
        name_and_size = name_and_size_from(name)
        mux = current_module.add_block(:ScanMux, name_and_size[0], icl: node, network: top_level)
        netlist.add_net(to_vector(selected_by,  path: mux.parent.path), to_vector(mux.path), :scanMux_selected_by)
        selections.each do |selection|
          from = to_vector(selection.to_a[1],  path: mux.parent.path)
          mux.add_input(to_number(selection.to_a[0]), from.path)
          netlist.add_net(from, to_vector(mux.path), :scanMux_selection)
        end
      end

      private

      def netlist
        network.netlist
      end

      def to_stem(path)
        if path.empty?
          ''
        else
          path + '.'
        end
      end

      def to_string(node)
        @to_string ||= ToString.new
        @to_string.process(node)
      end

      def to_vector(node, options={})
        if node.is_a?(String)
          v = Vector.new(node, nil, false, false)
        else
          @to_vector ||= ToVector.new
          v = @to_vector.process(node)
          v.path = to_stem(options[:path]) + v.path if options[:path]
        end
        v
      end

      def to_number(node)
        @to_number ||= ToNumber.new
        @to_number.process(node)
      end

      def name_and_size_from(node)
        if node.type == :vector_id && node.to_a[1].type == :range
          a = node.to_a
          [a[0].value, size_of(a[1])]
        elsif node.type == :SCALAR_ID
          [node.value, 1]
        else
          fail "Don't know how to extract name_and_size from node type #{node.type}!"
        end
      end

      def size_of(range)
        a, b = *range
        (a.value - b.value).abs + 1
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
