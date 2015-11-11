require 'ijtag/icl/processor'
module IJTAG
  module ICL
    class ToConnections < Processor
      def on_signal(node)
        nodes = process_all(node)
        nodes[0].type = node.type
        nodes
      end
      alias_method :on_scan_signal, :on_signal
      alias_method :on_data_signal, :on_signal

      def on_hier_port(node)
        p = process_all(node)
        v = p.pop
        stem = p.join('.')
        unless stem.empty?
          v.path = "#{stem}.#{v.path}"
        end
        v
      end

      def on_SCALAR_ID(node)
        nodes = process_all(node)
        Connection.new(nodes[0], nil)
      end

      def on_vector_id(node)
        nodes = process_all(node)
        Connection.new(nodes[0].to_s, nodes[1])
      end

      def on_POS_INT(node)
        node.children.first
      end

      def on_range(node)
        fail 'Not implemented yet'
      end
    end
  end
end
