module IJTAG
  module AST
    class Error < StandardError
      attr_reader :node

      def initialize(msg, node)
        @node = node
        if node.file
          msg += "\n#{node.file}:#{node.line_number}"
        else
          msg += "\nAt ICL source line #{node.line_number}:"
        end
        msg += "\n\n#{node.text_value}"
        super(msg)
      end
    end
  end
end
