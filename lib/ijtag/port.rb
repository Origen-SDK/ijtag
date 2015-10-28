module IJTAG
  # Represents an I/O port connection on a model
  class Port
    include Origen::Model

    attr_reader :size
    attr_reader :icl
    attr_reader :network
    attr_reader :type

    def initialize(options = {})
      @size = options[:size] || 1
      @icl = options[:icl]
      @network = options[:network]
      @type = options[:type]
    end

    def outputs
      output_paths.map { |p| network.path_to_node(p) }
    end
    alias_method :to, :outputs

    def output_paths
      (network.netlist.out_of[self.path] || []).map { |n| n.vector.path }
    end

    def inputs
      input_paths.map { |p| network.path_to_node(p) }
    end
    alias_method :from, :inputs

    def input_paths
      (network.netlist.into[self.path] || []).map { |n| n.vector.path }
    end
  end
end
