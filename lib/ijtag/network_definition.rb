module IJTAG
  class NetworkDefinition
    attr_reader :namespaces
    attr_reader :use_namespaces
    attr_reader :modules

    def initialize(icl_str=nil, options={})
      @namespaces = {}.with_indifferent_access
      @use_namespaces = {}.with_indifferent_access
      @modules = {}.with_indifferent_access

      icl_str, options = nil, icl_str if icl_str.is_a?(Hash)
      icl_str ||= File.read(options[:file])

      ast = ICL::Parser.parse(icl_str).to_ast
      ast = ICL::Resolver.new.process(ast)
      ICL::Importer.new(self).process(ast)
    end

    def instantiate(module_name)
      b = ICL::Builder.new(self)
      b.process(modules[module_name])
      b.top_level
    end
  end
end
