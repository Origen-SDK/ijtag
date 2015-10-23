require 'ast'
require 'treetop'
module IJTAG
  module AST
    class Node < ::AST::Node
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
