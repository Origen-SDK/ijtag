require 'ijtag/icl/processor'
module IJTAG
  module ICL
    class ToNumber < Processor
      def on_SIZED_POS_INT(node)
        process_all(node)[1]
      end

      def on_POS_INT(node)
        node.to_a[0]
      end
    end
  end
end
