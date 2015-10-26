require 'ast'
require 'treetop'
module IJTAG
  module AST
    class Node < ::AST::Node
      attr_reader :input, :interval

      # Returns the value at the root of an AST node like this:
      #
      #   node # => (module-def
      #               (module-name
      #                 (SCALAR-ID "Instrument"))
      #
      #   node.value  # => "Instrument"
      #
      # No error checking is done and the caller is responsible for calling
      # this only on compatible nodes
      def value
        val = children.first
        val = val.children.first while val.respond_to?(:children)
        val
      end

      # Returns the first child node of the given type that is found
      def find(type)
        find_all(type).first
      end

      # Returns an array containing all child nodes of the given type(s)
      def find_all(*types)
        Extractor.new.process(self, types)
      end

      def line_number
        input.line_of(interval.first)
      end

      def text_value
        input[interval]
      end



      protected

      # I'd rather see the true symbol
      def fancy_type
        @type
      end
    end
  end
end

# Some helpers to create the to_ast methods in syntax nodes
module Treetop
  module Runtime
    class SyntaxNode
      def n(type, *children)
        properties = children.pop if children.last.is_a?(Hash)
        IJTAG::AST::Node.new(type, children, properties || {})
      end

      def n0(type, properties={})
        n(type, *[], properties)
      end

      def n1(type, arg, properties={})
        n(type, *[arg], properties)
      end
    end
  end
end
