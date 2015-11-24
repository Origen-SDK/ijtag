module IJTAG
  module ICL
    module ExpressionProcessor
      def on_SIZED_POS_INT(node)
        nodes = process_all(node)
        Origen::SizedNumber.new(nodes[1], nodes[0])
      end

      def on_POS_INT(node)
        process_all(node)[0]
      end

      def on_add(node)
        left, right = *process_all(node)
        left + right
      end

      def on_subtract(node)
        left, right = *process_all(node)
        left - right
      end

      def on_multiply(node)
        left, right = *process_all(node)
        left * right
      end

      def on_divide(node)
        left, right = *process_all(node)
        left / right
      end

      def on_modulus(node)
        left, right = *process_all(node)
        left % right
      end

      def on_UNSIZED_BIN_NUMBER(node)
        nodes = process_all(node)
        nodes[0].to_i(2)
      end

      def on_UNSIZED_HEX_NUMBER(node)
        nodes = process_all(node)
        nodes[0].to_i(16)
      end

      # These just get rid of the size component so that it can be treated
      # like a regular number in additions, don't think the size is really
      # required anywhere
      def on_sized_number(node)
        nodes = process_all(node)
        Origen::SizedNumber.new(nodes[1], nodes[0])
      end
      alias_method :on_sized_dec_number, :on_sized_number
      alias_method :on_sized_bin_number, :on_sized_number
      alias_method :on_sized_hex_number, :on_sized_number
    end
  end
end
