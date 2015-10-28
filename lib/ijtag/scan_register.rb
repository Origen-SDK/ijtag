module IJTAG
  class ScanRegister
    include Origen::Model

    attr_reader :size
    attr_reader :icl
    attr_reader :network

    def initialize(options = {})
      @size = options[:size]
      @icl = options[:icl]
      @network = options[:network]

      reg :dr, 0, size: size, path: :hidden do |reg|
        reg.bit (size - 1)..0, :data
      end
    end

    # Returns an array of network nodes that are connected to the register's scan out path
    def so
      so_paths.map { |p| network.path_to_node(p) }
    end

    def so_paths
      network.netlist.out_of[self.path].select { |n| n.vector.index == 0  || n.type == :ScanOutPort_source }.
        map { |n| n.vector.path }
    end

    # Returns the network node that is the register's scan in source
    def si
      si_paths.map { |p| network.path_to_node(p) }
    end

    def si_paths
      network.netlist.into[self.path].select { |n| n.type == :scanInSource }.
        map { |n| n.vector.path }
    end

    def capture
      capture_paths.map { |p| network.path_to_node(p) }
    end

    def capture_paths
      network.netlist.into[self.path].select { |n| n.type == :captureSource }.
        map { |n| n.vector.path }
    end

    def update
      update_paths.map { |p| network.path_to_node(p) }
    end

    def update_paths
      network.netlist.out_of[self.path].select { |n| n.type == :DataOutPort_source }.
        map { |n| n.vector.path }
    end

    # Proxy all other methods to the register object, this implements things
    # like network.sr[0] which will return the bit 0 object
    def method_missing(method, *args, &block)
      if reg(:dr).respond_to?(method)
        reg(:dr).send(method, *args, &block)
      else
        super
      end
    end

    def respond_to?(method)
      # This if is a bit of a hack since Origen seems to call respond_to? before
      # the dr reg is instantiated
      if has_reg?(:dr)
        super || reg(:dr).respond_to?(method)
      else
        super
      end
    end
  end
end
