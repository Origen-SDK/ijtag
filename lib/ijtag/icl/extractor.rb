require 'ijtag/icl/processor'
module IJTAG
  module ICL
    class Extractor < Processor
      include ::AST::Processor::Mixin

      attr_reader :types
      attr_reader :results

      def find(node, *types)
        @types = types
        @results = []
        node = AST::Node.new(:wrapper, node) unless node.respond_to?(:to_ast)
        process(node)
        results
      end

      def handler_missing(node)
        @results << node if types.include?(node.type)
        super
      end
    end
  end
end
