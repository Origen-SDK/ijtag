module IJTAG
  module ICL
    Vector = Struct.new(:path, :index, :index?, :range?) do
      def to_s
        if index?
          if range?
            "#{path}[#{index.first}:#{index.last}]"
          else
            "#{path}[#{index}]"
          end
        else
          path
        end
      end
    end
  end
end
