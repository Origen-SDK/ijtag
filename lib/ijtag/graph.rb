module IJTAG
  class Graph
    class Node
      attr_reader :predecessor, :graph, :model
      def initialize(model, predecessor, graph)
        @model = model
        @graph = graph
        @predecessor = predecessor
        successors
      end

      def path
        model.path
      end

      # Returns the successor nodes connected to this scan register. Port objects will
      # only be returned if they are edge connections, otherwise the parent object of
      # any connected ports will be returned (e.g. a downstream MUX object rather than
      # one of its input ports)
      def successors(options = {})
        @successors ||= begin
          if model.is_a?(ScanRegister)
            nodes = next_level(model.so)
          elsif model.is_a?(Origen::Models::Mux)
            nodes = next_level(model.output)
          elsif model.is_a?(Origen::Ports::Port)
            nodes = predecessor ? [] : next_level(model)
          else
            fail "Unknown network model type: #{model.class}"
          end
          nodes.map { |n| graph.node(n, self) }
        end
      end

      def to_img(graph = nil)
        if graph
          if model.is_a?(ScanRegister)
            graph.rectangle << graph.node(path)
          elsif model.is_a?(Origen::Models::Mux)
            n = graph.node(path)
            graph.rectangle << n
            n.label "MUX (#{path})"
          end
          successors.reverse_each do |s|
            graph.edge path, s.path
            s.to_img(graph)
          end
        else
          require 'graph'
          graph = ::Graph.new('G')
          graph.rotate
          to_img(graph)
          graph.save 'simple_example', 'png'
        end
      end

      private

      def next_level(port, options = {})
        chain = (options[:chain] || []).dup
        chain << port
        ports = (port.ports - chain)
        if ports.empty?
          [port]
        else
          ports.map do |p|
            current_chain = chain.dup
            if p.parent.is_a?(ScanRegister)
              p.parent
            elsif p.parent.is_a?(Origen::Models::Mux)
              p.parent
            else
              next_level(p, chain: current_chain)
            end
          end.flatten.compact
        end
      end
    end

    # Fast node lookup by path
    attr_reader :lookup

    def initialize(network)
      @lookup = {}
      n = network.default_si
      node(network.default_si, nil)
    end

    def node(obj, predecessor)
      @lookup[obj.path] = Node.new(obj, predecessor, self)
    end
  end
end
