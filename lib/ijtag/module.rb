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

    def scan_interfaces
      @scan_interfaces ||= {}.with_indifferent_access
    end

    def path_to_node(path)
      unless node = eval("self.#{path}")
        fail "Node #{path} was not found!"
      end
      node
    end

    def add_block(type, name, options = {})
      options = options.merge(class_name: type.to_s)
      block = sub_block name, options
      connect_sr(block) if block.is_a?(Origen::Models::ScanRegister)
      lower_case_alias = name.to_s.symbolize
      unless lower_case_alias == name.to_sym
        define_singleton_method lower_case_alias do
          send(name)
        end
      end
      @cache = {}
      block
    end

    def scan_registers
      @cache[:scan_registers] ||= sub_blocks.select { |k, v| v.is_a?(Origen::Models::ScanRegister) }
    end

    def shift!(val = 0)
      with_select do
        with_shift do
          ports.by_type['ScanInPort'].first.drive(val)
          clock!
        end
      end
    end

    def update!
      with_select do
        with_update do
          clock!
        end
      end
    end

    def capture!
      with_select do
        with_capture do
          clock!
        end
      end
    end

    def selected?
      ports.by_type['SelectPort'].first.data == 1
    end

    def shift?
      selected? && ports.by_type['ShiftEnPort'].first.data == 1
    end

    def capture?
      selected? && ports.by_type['CaptureEnPort'].first.data == 1
    end

    def update?
      selected? && ports.by_type['UpdateEnPort'].first.data == 1
    end

    private

    def with_select
      ports.by_type['SelectPort'].first.drive(1)
      yield
      ports.by_type['SelectPort'].first.drive(0)
    end

    def with_capture
      ports.by_type['CaptureEnPort'].first.drive(1)
      yield
      ports.by_type['CaptureEnPort'].first.drive(0)
    end

    def with_shift
      ports.by_type['ShiftEnPort'].first.drive(1)
      yield
      ports.by_type['ShiftEnPort'].first.drive(0)
    end

    def with_update
      ports.by_type['UpdateEnPort'].first.drive(1)
      yield
      ports.by_type['UpdateEnPort'].first.drive(0)
    end

    def connect_sr(sr)
      sr.ue.connect_to { update? ? 1 : 0 }
      sr.se.connect_to { shift? ? 1 : 0 }
      sr.ce.connect_to { capture? ? 1 : 0 }
    end

    # Performs final default hookup once all all blocks are instantiated, e.g. connect
    # all scan registers to their modules scan interface ports
    def finalize
      sub_blocks.each do |name, block|
        if block.is_a?(IJTAG::Module)
          block.send(:finalize)
        elsif block.is_a?(Origen::Models::ScanRegister)
        end
      end
      self
    end
  end
end
