require 'ijtag/icl/processor'
module IJTAG
  module ICL
    class ToVector < Processor
      def on_hier_port(node)
        p = process_all(node).join('.')
        Vector.new(p.to_s, nil, false, false)
      end

      def on_SCALAR_ID(node)
        nodes = process_all(node)
        Vector.new(nodes[0], nil, false, false)
      end

      def on_vector_id(node)
        nodes = process_all(node)
        Vector.new(nodes[0].to_s, nodes[1], true, nodes[1].is_a?(Range))
      end

      def on_POS_INT(node)
        node.children.first
      end

      def on_range(node)
        fail "Not implemented yet"
      end
    end
  end
end
