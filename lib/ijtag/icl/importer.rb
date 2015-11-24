# rubocop:disable Style/MethodName: Use snake_case for method names.
require 'ijtag/icl/processor'
module IJTAG
  module ICL
    class ImportError < AST::Error
    end

    # Imports all top-level definitions into a Ruby NetworkDefinition instance
    class Importer < Processor
      attr_reader :network_def

      def initialize(network_def)
        @network_def = network_def
      end

      def on_include(node)
        f = node.value
        unless File.exist?(f)
          if node.directory && File.exist?("#{node.directory}/#{f}")
            f = "#{node.directory}/#{f}"
          else
            fail BuildError.new("Can't find include file #{f}", node)
          end
        end
        ast = ICL::Parser.parse(File.read(f), file: f).to_ast
        process(ast)
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
# rubocop:enable Style/MethodName: Use snake_case for method names.
