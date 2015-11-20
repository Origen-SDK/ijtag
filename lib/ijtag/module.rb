require 'ijtag/scan_interfaces'
module IJTAG
  # Corresponds to an ICL module instance
  class Module
    include Origen::Model
    include IJTAG::Aliases
    include IJTAG::Enumerations
    include IJTAG::ScanInterfaces

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

    def path_to_node(path)
      @path_to_node ||= {}
      if node = @path_to_node[path] ||= eval("self.#{path}")
        node
      else
        fail "Node #{path} was not found!"
      end
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
      block
    end

    def shift!(*args)
      client_interfaces[0].shift!(*args)
    end

    def update!
      client_interfaces[0].update!
    end

    def capture!
      client_interfaces[0].capture!
    end

    # Returns the length of the chain between a modules SI port and SO port
    def chain_length(timeout = 1000)
      # There may be a quicker way of doing this by inspecting the netlist, but
      # that could be difficult and may need to build a lot of knowledge about the
      # circuit behavior into such an analyzer. So instead for now we will just shift
      # some known data into SI and count how long it takes to come out the other side.

      # Something suitably long and random
      data = '1011101101000110110001101100011010101111111100000001010110100101'.to_i(2)
      matched = false
      read_data = 0
      i = 0
      while !matched && i < (timeout + 64)
        shift!(data[i])
        data_out = client_interfaces[0].so.data
        read_data >>= 1
        read_data |= data_out << 63
        read_data &= 0xFFFF_FFFF_FFFF_FFFF
        if read_data == data
          matched = true
        else
          i += 1
        end
      end

      if i == (timeout + 64)
        fail "The chain is either not complete, or longer than #{timeout}"
      else
        i - 62
      end
    end

    private

    def root
      r = path
      r += '.' unless r.empty?
      r
    end

    def connect_sr(sr)
      sr.ue.connect_to "#{root}client_interfaces[0].ue"
      sr.se.connect_to "#{root}client_interfaces[0].se"
      sr.ce.connect_to "#{root}client_interfaces[0].ce"
    end

    def connect_module(mod)
      unless mod.client_interfaces.empty?
        mod.client_interfaces[0].ue.connect_to "#{root}client_interfaces[0].ue"
        mod.client_interfaces[0].se.connect_to "#{root}client_interfaces[0].se"
        mod.client_interfaces[0].ce.connect_to "#{root}client_interfaces[0].ce"
      end
    end
  end
end
