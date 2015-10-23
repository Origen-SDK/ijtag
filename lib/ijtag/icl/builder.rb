module IJTAG
  module ICL
    module Builder
      class << self
        def build(icl)
          Network.new
        end
      end
    end
  end
end
