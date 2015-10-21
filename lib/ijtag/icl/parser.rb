require 'treetop'
module IJTAG
  module ICL
    # Responsible for parsing an 1687 ICL file to an AST
    class Parser

      def self.parse(data)
        tree = parser.parse(data)

        # If the AST is nil then there was an error during parsing
        # we need to report a simple error message to help the user
        if(tree.nil?)
          parser.failure_reason =~ /^(Expected .+) (after|at)/m
          @last_error_msg = []
          @last_error_msg << "#{$1.gsub("\n", '$NEWLINE')}:"
          @last_error_msg << data.lines.to_a[parser.failure_line - 1]
          @last_error_msg << "#{'~' * (parser.failure_column - 1)}^"
          puts @last_error_msg
        end
        tree
      end

      def self.last_error_msg
        @last_error_msg || []
      end

      def self.parser
        @parser ||= begin
          grammar = File.join(File.expand_path(File.dirname(__FILE__)), 'grammar.treetop')
          Treetop.load(grammar)
          GrammarParser.new
        end
      end
    end
  end
end
