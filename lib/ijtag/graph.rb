module IJTAG
  class Graph
    # Fast node lookup by path
    attr_reader :lookup
    attr_reader :sibs_by_mux

    def initialize(network)
      @sibs_by_mux = {}
      @lookup = {}
      n = network.default_si
      node(:si, network.default_si, nil)
    end

    def node(type, obj, predecessor, meta = {})
      @lookup[obj.path] = Node.new(type, obj, predecessor, self, meta)
    end
  end
end
