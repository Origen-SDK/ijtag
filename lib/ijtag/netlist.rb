module IJTAG
  class Netlist
    attr_reader :inputs, :outputs, :network

    def initialize(network)
      @network = network
      @inputs = {}.with_indifferent_access
      @outputs = {}.with_indifferent_access
    end

    def add_net(to, from, type)
      nets << [to, from, type]
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
