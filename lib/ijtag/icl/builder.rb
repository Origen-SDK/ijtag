require 'ijtag/icl/processor'
module IJTAG
  module ICL
    class Builder < Processor
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
          model = network.sub_block name.value, class_name: 'IJTAG::Instrument'
        else
          model = Module.new
          @top_level = model
        end
        define_module(model) do
          process_all(items)
        end
      end

      def on_port_def(node)
        name, *items = *process_all(node)

        if name.type == :vector_id && name.to_a[1].type == :range
          v = name.to_a
          current_module.add_port(v[0].value, size: size_of(v[1]))
        else
          current_module.add_port(name.value)
        end

        if items.size > 0
          #fail 'Port def items not implemented yet!'
        end
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
        current_module.scan_interfaces << node
      end

      def on_scanRegister_def(node)
        name, *items = *process_all(node)
        debugger
      end

      private

      def size_of(range)
        a, b = *range
        (a.value - b.value).abs + 1
      end

      def define_module(model)
        modules.push model
        yield
        modules.pop
      end

      def modules
        @modules ||= []
      end

      def current_module
        modules.last
      end
    end
  end
end
