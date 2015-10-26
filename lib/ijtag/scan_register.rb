module IJTAG
  class ScanRegister
    include Origen::Model

    attr_reader :size
    attr_reader :icl
    attr_reader :network

    def initialize(options = {})
      @size = options[:size]
      @icl = options[:icl]
      @network = options[:network]
    end
  end
end
