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

    def [](index)
      d = ports.by_type['DataOutPort']
      if d && d[0]
        d[0][index]
      else
        fail "Module #{path} does not have a data out port!"
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
      default_client_interface.shift!(*args)
    end

    def shift_ir!(*args)
      default_client_interface.shift_ir!(*args)
    end

    def shift_dr!(*args)
      default_client_interface.shift_dr!(*args)
    end

    def default_client_interface
      client_interfaces[0] || client_tap_interfaces[0]
    end

    def update!
      client_interfaces[0].update!
    end

    def capture!
      client_interfaces[0].capture!
    end

    def tap
      client_tap_interfaces.first.tap
    end

    def tap_driver
      client_tap_interfaces.first.tap_driver
    end

    def so_visible?
      connected?(default_so, local_top_level.default_so)
    end

    def connected?(p1, p2)
      !!nodes_between(p1, p2)
    end

    def chain_length(options = {})
      options = {
        si: default_si,
        so: default_so
      }.merge(options)
      if nodes = nodes_between(options[:si], options[:so])
        nodes.reduce(0) do |sum, node|
          if node.is_a?(Origen::Models::ScanRegister)
            sum + node.size
          else
            sum
          end
        end
      end
    end

    def default_si
      if !client_interfaces.empty?
        client_interfaces[0].si
      elsif !client_tap_interfaces.empty?
        client_tap_interfaces[0].si
      else
        fail 'Module has no scan in port'
      end
    end

    def default_so
      if !client_interfaces.empty?
        client_interfaces[0].so
      elsif !client_tap_interfaces.empty?
        client_tap_interfaces[0].so
      else
        fail 'Module has no scan out port'
      end
    end

    def nodes_between(p1, p2, nodes = [])
      chain = (nodes.dup) << p1
      (p1.ports - chain).map do |port|
        current_chain = chain.dup
        if port == p2
          current_chain << port
        else
          if port.parent.is_a?(Origen::Models::Mux) && port.path =~ /input\d+$/
            if port.parent.active_input == port
              out = port.parent.output
              current_chain << port
              current_chain << port.parent
              nodes_between(out, p2, current_chain)
            end
          elsif port.parent.is_a?(Origen::Models::ScanRegister) &&
                port.parent.si == port
            current_chain << port
            current_chain << port.parent
            nodes_between(port.parent.so, p2, current_chain)
          else
            nodes_between(port, p2, current_chain)
          end
        end
      end.compact.first
    end

    def chain(options = {})
      options = {
        si: default_si,
        so: default_so
      }.merge(options)
      nodes = nodes_between(options[:si], options[:so])
      if nodes
        nodes.map do |node|
          if node.is_a?(Origen::Models::ScanRegister)
            node.path
          elsif node.is_a?(Origen::Models::Mux)
            node.path
          else
            node.path
          end
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

    def clock_prepare
      client_tap_interfaces.each do |int|
        int.tap.clock_prepare
      end
    end

    def clock_apply
      client_tap_interfaces.each do |int|
        int.tap.clock_apply
      end
    end

    def siblings
      parent.modules
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
