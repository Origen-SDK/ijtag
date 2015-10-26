require 'ijtag/icl/processor'
require 'ijtag/icl/numeric_expression_processor'
module IJTAG
  module ICL
    class BuildError < AST::Error
    end

    class Builder < Processor
      include NumericExpressionProcessor

      # Returns the built network object after the processor has run
      attr_reader :network
      attr_reader :module_defs
      attr_reader :top_level

      def initialize(network_def)
        @network_def = network_def
      end

      def on_module_def(node)
        name, *items = *node
        if top_level
          #model = network.sub_block name.value, class_name: 'IJTAG::Instrument'
          fail "Oops, something has gone wrong!"
        else
          model = Module.new
          @top_level = model
        end
        define_module(model) do
          process_all(items)
        end
      end

      def on_parameter_def(node)
        name, val = *process_all(node)
        parameters[name.value] = val
      end

      def on_parameter_ref(node)
        parameters[node.value]
      end

      def on_port_def(node)
        name, *items = *process_all(node)
        name_and_size = name_and_size_from(name)
        current_module.add_block(:Port, name_and_size[0], size: name_and_size[1], ast: node)
      end
      alias_method :on_scanInPort_def, :on_port_def
      alias_method :on_scanOutPort_def, :on_port_def
      alias_method :on_shiftEnPort_def, :on_port_def
      alias_method :on_captureEnPort_def, :on_port_def
      alias_method :on_updateEnPort_def, :on_port_def
      alias_method :on_selectPort_def, :on_port_def
      alias_method :on_resetPort_def, :on_port_def
      alias_method :on_tckPort_def , :on_port_def
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
        elements = {attributes: []}
        items.each do |item|
          if item.type == :attribute_def
            elements[:attributes] << item
          elsif elements[item.type]
            raise BuildError.new("A ScanRegister definition can declare only one #{item.type.to_s.camelize}", node)
          else
            elements[item.type] = item
          end
        end
        unless elements[:scanInSource]
          raise BuildError.new("A ScanRegister definition must declare a ScanInSource", node)
        end
        current_module.add_block(:ScanRegister, name_and_size[0], size: name_and_size[1], ast: node)
      end

      private

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
