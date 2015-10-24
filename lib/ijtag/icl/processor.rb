require 'ast'
module IJTAG
  module ICL
    # Base class for processing the ICL AST, it provides default handlers
    # that ensure that all nodes get processed
    class Processor
      include ::AST::Processor::Mixin

      # Helper to create new nodes
      def n(type, *children)
        IJTAG::AST::Node.new(type, children)
      end

      # Default handler for the terminal nodes, do nothing
      def process_terminal(node)
      end
      alias_method :on_SCALAR_ID, :process_terminal
      alias_method :on_POS_INT, :process_terminal

      # Most of the ICL nodes are non-terminals, so process them all by default
      def handler_missing(node)
        node.updated(nil, process_all(node.children))
      end
    end
  end
end
