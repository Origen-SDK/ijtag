# rubocop:disable Style/MethodName: Use snake_case for method names.
require 'ijtag/icl/processor'
require 'ijtag/icl/expression_processor'
module IJTAG
  module ICL
    class LogicProcessor < Processor
      include ExpressionProcessor

      def evaluate(node, context)
        ruby = process(node)
        context.instance_eval(ruby)
      end

      def on_concat_data_signal(node)
        nodes = process_all(node)
        "Origen::Ports::Connection.new(nil, #{nodes.join(', ')}).data"
      end

      def on_vector_id(node)
        nodes = process_all(node)
        id = Connection.new(nodes[0], index: nodes[1]).to_s
        id =~ /^self/ ? id : "self.#{id}"
      end

      def on_signal(node)
        nodes = process_all(node)
        if nodes.size > 1
          fail BuildError.new('Signal definition expects only one child', node)
        end
        Connection.new(nodes[0], type: node.type).to_s
      end
      alias_method :on_scan_signal, :on_signal
      alias_method :on_data_signal, :on_signal
      alias_method :on_reset_signal, :on_signal

      def on_SCALAR_ID(node)
        id = node.children.first
        "self.#{id}"
      end

      def on_equal(node)
        nodes = process_all(node)
        "#{nodes[0]} == #{nodes[1]};"
      end
    end
  end
end
# rubocop:enable Style/MethodName: Use snake_case for method names.
