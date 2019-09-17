module IJTAG
  class Graph
    autoload :Node, "ijtag/graph/node"

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
      case type
      when :sib
        n = SIB.new(obj, predecessor, self, meta)
      when :mux
        n = Mux.new(obj, predecessor, self, meta)
      when :si, :so, :port
        n = Port.new(obj, predecessor, self, meta)
      when :sr
        n = ScanRegister.new(obj, predecessor, self, meta)
      else
        fail "Unknown graph node type: #{type}"
      end

      @lookup[obj.path] = n
    end
  end
end
