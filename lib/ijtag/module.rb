module IJTAG
  # Corresponds to an ICL module instance
  class Module
    include Origen::Model
    include IJTAG::Aliases
    include IJTAG::Enumerations

    alias :blocks :sub_blocks

    def scan_interfaces
      @scan_interfaces ||= {}.with_indifferent_access
    end

    def add_block(type, name, options={})
      options = options.merge(class_name: type.to_s.camelize)
      sub_block name, options
      lower_case_alias = name.to_s.symbolize
      unless lower_case_alias == name.to_sym
        define_singleton_method lower_case_alias do
          send(name)
        end
      end
      @cache = {}
    end

    def ports
      @cache[:ports] ||= sub_blocks.select{ |k,v| v.is_a?(Port) }
    end

    def scan_registers
      @cache[:scan_registers] ||= sub_blocks.select{ |k,v| v.is_a?(ScanRegister) }
    end
  end
end
