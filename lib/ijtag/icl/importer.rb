require 'ijtag/icl/processor'
module IJTAG
  module ICL
    # Imports all top-level definitions into a Ruby NetworkDefinition instance
    class Importer < Processor
      attr_reader :network_def

      def initialize(network_def)
        @network_def = network_def
      end

      def on_module_def(node)
        name = node.to_a[0].value
        network_def.modules[name] = node
      end

      def on_nameSpace_def(node)
      end

      def on_useNameSpace_def(node)
      end
    end
  end
end
