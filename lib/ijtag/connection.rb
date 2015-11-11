module IJTAG
  module ICL
    Connection = Struct.new(:path, :index) do
      attr_accessor :type, :size

      def index?
        !!index
      end

      def range?
        index.is_a?(Range)
      end

      def to_s
        path + index_s
      end

      def add_root(root)
        if root
          self.path = to_stem(root) + path
        end
      end

      def size
        @size || begin
          if index?
            if range?
              index.to_a.size
            else
              1
            end
          end
        end
      end

      def index_s(relative_to = nil)
        if index?
          if relative_to
            if range?
              "[#{relative_to + size - 1}:#{relative_to}]"
            else
              "[#{relative_to}]"
            end
          else
            if range?
              "[#{index.first}:#{index.last}]"
            else
              "[#{index}]"
            end
          end
        else
          ''
        end
      end

      private

      def to_stem(path)
        if path.empty?
          ''
        else
          path + '.'
        end
      end
    end
  end
end
