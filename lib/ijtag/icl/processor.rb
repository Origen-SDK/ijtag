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

      def process(node)
        if node.respond_to?(:to_ast)
          super(node) 
        else
          node
        end
      end

      def handler_missing(node)
        node.updated(nil, process_all(node.children))
      end
    end
  end
end
