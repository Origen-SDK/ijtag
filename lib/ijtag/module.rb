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
    attr_reader :scan_registers, :modules
    attr_reader :allow_broadcast

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
      @scan_registers = []
      @modules = []
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
      if block.is_a?(Origen::Models::ScanRegister)
        @scan_registers << block
      else
        @modules << block if block.is_a?(IJTAG::Module)
      end
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

    def so_visible?
      connected?(so, local_top_level.so)
    end

    def connected?(p1, p2)
      !!nodes_between(p1, p2)
    end

    def chain_length
      if nodes = nodes_between(si, so)
        nodes.reduce(0) do |sum, node|
          if node.is_a?(Origen::Models::ScanRegister)
            sum + node.size
          else
            sum
          end
        end
      end
    end

    def nodes_between(p1, p2, nodes = [])
      nodes = (nodes.dup) << p1
      (p1.ports - nodes).map do |port|
        if port == p2
          nodes << port
        else
          if port.parent.is_a?(Origen::Models::Mux) && port.path =~ /input\d+$/
            if port.parent.active_input == port
              out = port.parent.output
              nodes << port
              nodes << port.parent
              nodes_between(out, p2, nodes)
            end
          elsif port.parent.is_a?(Origen::Models::ScanRegister) &&
                port.parent.si == port
            nodes << port
            nodes << port.parent
            nodes_between(port.parent.so, p2, nodes)
          else
            nodes_between(port, p2, nodes)
          end
        end
      end.compact.first
    end

    def chain
      nodes_between(si, so).map do |node|
        if node.is_a?(Origen::Models::ScanRegister)
          node.path
        elsif node.is_a?(Origen::Models::Mux)
          node.path
        else
          node.path
        end
      end
    end

    # Returns the length of the chain between a modules SI port and SO port
    def orig_chain_length(options = {})
      options = {
        input:           si,
        output:          client_interfaces[0].so,
        timeout:         1000,
        fail_on_timeout: true
      }.merge(options)
      result = nil
      preserve_scan_register_data do
        options[:input].preserve_drive_data do
          # There may be a quicker way of doing this by inspecting the netlist, but
          # that could be difficult and may need to build a lot of knowledge about the
          # circuit behavior into such an analyzer. So instead for now we will just shift
          # some known data into SI and count how long it takes to come out the other side.

          # Something suitably long and random
          data = '1011101101000110110001101100011010101111111100000001010110100101'.to_i(2)
          matched = false
          read_data = 0
          i = 0
          while !matched && i < (options[:timeout] + 64)
            options[:input].drive(data[i])
            shift!
            data_out = options[:output].data
            read_data >>= 1
            read_data |= data_out << 63
            read_data &= 0xFFFF_FFFF_FFFF_FFFF
            if read_data == data
              matched = true
            else
              i += 1
            end
          end

          if i == (options[:timeout] + 64)
            if options[:fail_on_timeout]
              fail "The chain is either not complete, or longer than #{options[:timeout]}"
            else
              result = nil
            end
          else
            result = i - 62
          end
        end
      end
      result
    end

    # Returns not only the scan registers that are immediate children of this module, but
    # also those are embedded within child modules
    def all_scan_registers
      @all_scan_registers ||= begin
        s = scan_registers.dup
        modules.each do |mod|
          s += mod.all_scan_registers
        end
        s
      end
    end

    def can_be_in_broadcast_config?
      allow_broadcast || (parent && parent.can_be_in_broadcast_config?)
    end

    private

    def preserve_scan_register_data
      all_scan_registers.each(&:save_sr_data)
      yield
      all_scan_registers.each(&:restore_sr_data)
    end

    def root
      r = path
      r += '.' unless r.empty?
      r
    end
  end
end
