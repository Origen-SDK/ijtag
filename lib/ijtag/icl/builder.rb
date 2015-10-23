require 'ijtag/icl/processor'
module IJTAG
  module ICL
    class Builder < Processor
      # Returns the built network object after the processor has run
      attr_reader :network
      attr_reader :extractor

      def initialize
        @extractor = Extractor.new
      end

      def on_icl_source(node)
        @network = Network.new
        process_all(node.children)
      end

      def on_module_def(node)
        name = root_value(extractor.find(node, :module_name).first)
        network.sub_block name, class_name: 'IJTAG::Instrument'
        process_all(node.children)
      end
    end
  end
end
