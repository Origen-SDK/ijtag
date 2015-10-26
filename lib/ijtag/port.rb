module IJTAG
  # Represents an I/O port connection on a model
  class Port
    include Origen::Model

    attr_reader :size
    attr_reader :icl

    def initialize(options = {})
      @size = options[:size] || 1
      @icl = options[:icl]
    end
  end
end
