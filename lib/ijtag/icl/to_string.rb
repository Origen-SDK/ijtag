require 'ijtag/icl/processor'
module IJTAG
  module ICL
    class ToString < Processor
      def on_hier_port(node)
        process_all(node).join('.')
      end

      def on_SCALAR_ID(node)
        node.children.first
      end

      def on_vector_id(node)
        nodes = process_all(node)
        "#{nodes[0]}[#{nodes[1]}]"
      end

      def on_POS_INT(node)
        node.children.first.to_s
      end
    end
  end
end
