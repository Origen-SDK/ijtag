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
  end
end
