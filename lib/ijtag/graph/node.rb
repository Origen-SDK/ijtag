module IJTAG
  class Graph
    class Node
      attr_reader :predecessor, :graph, :model, :type, :meta
      def initialize(type, model, predecessor, graph, meta = {})
        @meta = meta
        @type = type
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
            debugger
            next_level(model.so)
          elsif model.is_a?(Origen::Models::Mux)
            next_level(model.output)
          elsif model.is_a?(Origen::Ports::Port)
            if type == :sib
              outputs = [meta[:unprocessed_ports], meta[:sr].so].flatten
              outputs.map { |n| next_level(n, chain: [model]) }.flatten
            else
              predecessor ? [] : next_level(model)
            end
          else
            fail "Unknown network model type: #{model.class}"
          end
        end
      end

      def to_img(img = nil, options={})
        img, options = nil, img if img.is_a?(Hash)
        if img
          if model.is_a?(ScanRegister)
            img.rectangle << img.node(path)
          elsif model.is_a?(Origen::Models::Mux)
            n = img.node(path)
            img.rectangle << n
            n.label "MUX (#{path})"
          elsif type == :sib
            n = img.node(path)
            img.rectangle << n
            n.label 'SIB'
          end
          successors.each do |s|
            img.edge path, s.path
            s.to_img(img)
          end
        else
          require 'graph'
          img = ::Graph.new('G')
          img.rotate
          to_img(img)
          img.save "#{RGen.root}/output/icl_network", 'png'
        end
      end

      private

      def next_level(port, options = {})
        chain = (options[:chain] || []).dup
        chain << port
        ports = (port.ports - chain)
        if ports.empty?
          [graph.node(:so, port, self)]
        else
          ports.map do |p|
            current_chain = chain.dup
            if p.parent.is_a?(ScanRegister)
              graph.node(:sr, p.parent, self)
            elsif p.parent.is_a?(Origen::Models::Mux)
              graph.node(:mux, p.parent, self)
            else
              if meta = sib_boundary(p)
                if graph.sibs_by_mux[meta[:mux]]
                  next_level(meta[:sr].so)
                else
                  meta[:unprocessed_ports] = (p.ports - chain).reject do |prt|
                    prt.parent.is_a?(Origen::Models::Mux) && prt.id.to_s =~ /^input\d+$/
                  end
                  # Because the of the way this recursively builds, need to set a non-true
                  # value up front so that the above if branch will be taken
                  graph.sibs_by_mux[meta[:mux]] = true
                  graph.sibs_by_mux[meta[:mux]] = graph.node(:sib, p, self, meta)
                end
              else
                next_level(p, chain: current_chain)
              end
            end
          end.flatten.compact
        end
      end

      # Returns meta data (about the SIB) if the given port is determined to be on the
      # boundary of a SIB
      def sib_boundary(port)
        mi = port.ports.find { |p| p.parent.is_a?(Origen::Models::Mux) && p.id.to_s =~ /^input\d+$/ }
        if mi && mi.parent.number_of_options == 2 &&
           mi.parent.select.connections.size == 1
          if r = mi.parent.select.connections[0].send(:cleaned_nodes)[0][:obj]
            if r.is_a?(Origen::Registers::Reg) &&
               r.parent.is_a?(ScanRegister) && r.size == 1
              { mux: mi.parent, sr: r.parent }
            end
          end
        end
      end
    end
  end
end
