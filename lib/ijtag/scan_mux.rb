module IJTAG
  class ScanMux
    include Origen::Model

    attr_reader :icl
    attr_reader :network
    attr_reader :input_map

    def initialize(options = {})
      @icl = options[:icl]
      @network = options[:network]
      @input_map = {}
    end

    def inputs
      input_map.map { |k, v| [k, [network.path_to_node(v)]] }.to_h
    end
    alias_method :from, :inputs

    def add_input(val, path)
      @input_map[val] = path
    end
  end
end
