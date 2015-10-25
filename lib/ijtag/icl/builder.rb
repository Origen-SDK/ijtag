require 'ijtag/icl/processor'
module IJTAG
  module ICL
    class Builder < Processor
      # Returns the built network object after the processor has run
      attr_reader :network

      def on_icl_source(node)
        @network = Network.new
        process_all(node.children)
      end

      def on_module_def(node)
        name, *items = *node
        model = network.sub_block name.value, class_name: 'IJTAG::Instrument'
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
          fail "Port def items not implemented yet!"
        end
      end
      alias_method :on_dataInPort_def, :on_port_def
      alias_method :on_dataOutPort_def, :on_port_def

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
