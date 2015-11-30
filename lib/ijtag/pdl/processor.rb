require 'ast'
module IJTAG
  module PDL
    # Base class for processing the PDL AST, it provides default handlers
    # that ensure that all nodes get processed
    class Processor
      include ::AST::Processor::Mixin

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
