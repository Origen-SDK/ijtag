module IJTAG
  module ICL
    class Connection
      attr_accessor :type, :size, :path, :index

      def initialize(path, options = {})
        @size = options[:size]
        @index = options[:index]
        @type = options[:type]
        if path.is_a?(Connection)
          @size ||= path.size
          @index ||= path.index
          @type ||= path.type
          path = path.path
        elsif path =~ /(.*)\[(\d+):?(\d*)\]$/
          if Regexp.last_match(3).empty?
            path = Regexp.last_match(1)
            @index ||= Regexp.last_match(2).to_i
            @size ||= 1
          else
            path = Regexp.last_match(1)
            @index ||= ((Regexp.last_match(2).to_i)..(Regexp.last_match(3).to_i))
            @size ||= @index.to_a.size
          end
        end
        @path = path
        add_root(options[:root])
      end

      def numeric?
        path.is_a?(Numeric)
      end

      def each
        yield self
      end

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
          @path = to_stem(root) + path
        end
        self
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
