module IJTAG
  module ICL
    module NumericExpressionProcessor
      def compute_op(node)
        # Process all child nodes to convert everything to INTs and resolve parameters,
        # this will return something like this: [(POS-INT 2), (POS-INT 5)]
        nodes = process_all(node)

        values = nodes.map do |node|
          if node.type == :SIZED_POS_INT
            node.children[1].value
          else
            node.children[0]
          end
        end

        n :POS_INT, yield(values)
      end

      def on_add(node)
        compute_op(node) { |left, right| left + right }
      end

      def on_UNSIZED_BIN_NUMBER(node)
        nodes = process_all(node)
        n :POS_INT, nodes[0].to_i(2)
      end

      def on_UNSIZED_HEX_NUMBER(node)
        nodes = process_all(node)
        n :POS_INT, nodes[0].to_i(16)
      end

      # These just get rid of the size component so that it can be treated
      # like a regular number in additions, don't think the size is really
      # required anywhere
      def on_sized_number(node)
        n :SIZED_POS_INT, *process_all(node)
      end
      alias :on_sized_dec_number :on_sized_number
      alias :on_sized_bin_number :on_sized_number
      alias :on_sized_hex_number :on_sized_number
    end
  end
end
