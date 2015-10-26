module IJTAG
  # Represents an I/O port connection on a model
  class Port
    include Origen::Model

    attr_reader :size

    def initialize(options = {})
      @size = options[:size] || 1
    end
  end
end
