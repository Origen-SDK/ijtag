# rubocop:disable Style/MethodName: Use snake_case for method names.
require 'ijtag/icl/processor'
require 'ijtag/icl/expression_processor'
module IJTAG
  module ICL
    class LogicProcessor < Processor
      include ExpressionProcessor

      attr_reader :context

      def evaluate(node, context)
        @context = context
        result = process(node)
        if result == true
          1
        elsif result == false
          0
        else
          result
        end
      end

      def on_boolean_and(node)
        nodes = process_all(node)
        (data(nodes[0]) != 0) && (data(nodes[1]) != 0)
      end

      def on_boolean_or(node)
        nodes = process_all(node)
        (data(nodes[0]) != 0) || (data(nodes[1]) != 0)
      end

      def on_bitwise_not(node)
        nodes = process_all(node)
        ~(data(nodes[0]))
      end

      def on_bitwise_and(node)
        nodes = process_all(node)
        data(nodes[0]) & data(nodes[1])
      end

      def on_bitwise_or(node)
        nodes = process_all(node)
        data(nodes[0]) | data(nodes[1])
      end

      def on_bitwise_xor(node)
        nodes = process_all(node)
        data(nodes[0]) ^ data(nodes[1])
      end

      def on_concat_data_signal(node)
        nodes = process_all(node)
        Origen::Ports::Connection.new(nil, *nodes).data
      end

      def on_vector_id(node)
        nodes = process_all(node)
        v = Connection.new(nodes[0], index: nodes[1])
        obj = context.send(v.path)
        if v.index
          obj[v.index]
        else
          obj
        end
      end

      def on_signal(node)
        nodes = process_all(node)
        if nodes.size > 1
          fail BuildError.new('Signal definition expects only one child', node)
        end
        if nodes[0].is_a?(String)
          context.send(nodes[0])
        else
          nodes[0]
        end
      end
      alias_method :on_scan_signal, :on_signal
      alias_method :on_data_signal, :on_signal
      alias_method :on_reset_signal, :on_signal

      def on_SCALAR_ID(node)
        node.children.first
      end

      def on_equal(node)
        nodes = process_all(node)
        data(nodes[0]) == data(nodes[1])
      end

      def on_not_equal(node)
        nodes = process_all(node)
        data(nodes[0]) == data(nodes[1])
      end

      def data(obj)
        if obj.respond_to?(:data)
          obj.data
        else
          obj
        end
      end

      # Override the default behavior of returning the unmodified
      # node in the case of a handler returning false
      def process(node)
        return if node.nil?

        if node.respond_to?(:to_ast)
          node = node.to_ast

          # Invoke a specific handler
          on_handler = :"on_#{node.type}"
          if respond_to? on_handler
            send on_handler, node
          else
            handler_missing(node)
          end
        else
          node
        end
      end
    end
  end
end
# rubocop:enable Style/MethodName: Use snake_case for method names.
