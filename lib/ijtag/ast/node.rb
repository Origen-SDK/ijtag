require 'ast'
require 'treetop'
module IJTAG
  module AST
    class Node < ::AST::Node
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
        find(type)
      end

      # Returns an array containing all child nodes of the given type(s)
      def find_all(*types)
        Extractor.new.process(self, types)
      end
    end
  end
end

# Some helpers to create the to_ast methods in syntax nodes
module Treetop
  module Runtime
    class SyntaxNode
      def n(type, *children)
        IJTAG::AST::Node.new(type, children)
      end

      def n0(type)
        n(type, *[])
      end

      def n1(type, arg)
        n(type, *[arg])
      end
    end
  end
end
