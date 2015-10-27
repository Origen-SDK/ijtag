module IJTAG
  class Netlist
    attr_reader :inputs, :outputs

    def initialize
      @inputs = {}.with_indifferent_access
      @outputs = {}.with_indifferent_access
    end

    def add_net(to, from)
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
