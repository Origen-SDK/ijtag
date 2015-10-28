module IJTAG
  class Netlist
    # Returns a hash that maps all nodes that connect into a given node
    attr_reader :into
    # Returns a hash that maps all nodes that connect out of a given node
    attr_reader :out_of
    attr_reader :network

    Net = Struct.new(:vector, :type)

    def initialize(network)
      @network = network
      @into = {}.with_indifferent_access
      @out_of = {}.with_indifferent_access
    end

    def add_net(from, to, type)
      net_to = Net.new(to, type)
      net_from = Net.new(from, type)
      self.into[to.path] ||= []
      self.into[to.path] << net_from
      self.out_of[from.path] ||= []
      self.out_of[from.path] << net_to
    end

    private

    def nets
      @nets ||= []
    end

    # The netlist is cleaned up at the end once all modules have been
    # instantiated and are available for inspection
    def finalize
      nets.each do |to, from, type|
        to_obj = eval "network.#{to}"
        from_obj = eval "network.#{from}"

        if type == :ScanOutPort_source && from_obj = eval("network.#{from}").is_a?(ScanRegister)
          from = "#{from}[0]" unless from =~ /\]$/
        end

        apply_net(to, from)
      end
    end

    def apply_net(to, from)
      if inputs[to]
        fail "Net #{to} already has an input (#{inputs[to]}) and cannot be assigned to #{from}"
      else
        inputs[to] = from
      end
      if outputs[from]
        fail "Net #{from} already has an output (#{outputs[from]}) and cannot be assigned to #{to}"
      else
        outputs[from] = to
      end
    end
  end
end
