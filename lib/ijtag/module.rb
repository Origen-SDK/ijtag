module IJTAG
  # Corresponds to an ICL module instance
  class Module
    include Origen::Model
    include IJTAG::Aliases
    include IJTAG::Enumerations

    attr_reader :icl, :module_name, :instance_name
    attr_reader :network, :top_level

    alias_method :blocks, :sub_blocks
    alias_method :instance_name, :name

    def initialize(options = {})
      @icl = options[:icl]
      @module_name = options[:module_name]
      @top_level =  options[:top_level]
      if @top_level
        @network = self
      else
        @network = options[:network]
      end
    end

    def netlist
      if top_level
        @netlist ||= Netlist.new
      else
        network.netlist
      end
    end

    def scan_interfaces
      @scan_interfaces ||= {}.with_indifferent_access
    end

    def add_block(type, name, options = {})
      options = options.merge(class_name: type.to_s.camelize)
      block = sub_block name, options
      lower_case_alias = name.to_s.symbolize
      unless lower_case_alias == name.to_sym
        define_singleton_method lower_case_alias do
          send(name)
        end
      end
      @cache = {}
      block
    end

    def ports
      @cache[:ports] ||= sub_blocks.select { |k, v| v.is_a?(Port) }
    end

    def scan_registers
      @cache[:scan_registers] ||= sub_blocks.select { |k, v| v.is_a?(ScanRegister) }
    end
  end
end
