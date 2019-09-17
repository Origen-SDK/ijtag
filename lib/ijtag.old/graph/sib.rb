module IJTAG
  class Graph
    class SIB < Node
      def successors(options = {})
        @successors ||= begin
          outputs = [meta[:unprocessed_ports], meta[:sr].so].flatten
          outputs.map { |n| next_level(n, chain: [model]) }.flatten
        end
      end

      def to_img(img)
        n = img.node(path)
        img.rectangle << n
        n.label 'SIB'
      end
    end
  end
end
