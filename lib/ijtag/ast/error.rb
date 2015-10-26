module IJTAG
  module AST
    class Error < StandardError
      attr_reader :node

      def initialize(msg, node)
        @node = node
        msg += "\nAt ICL source line #{node.line_number}:"
        msg += "\n\n#{node.text_value}"
        super(msg)
      end
    end
  end
end
