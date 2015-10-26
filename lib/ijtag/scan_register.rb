module IJTAG
  class ScanRegister
    include Origen::Model

    attr_reader :size
    attr_reader :icl

    def initialize(options = {})
      @size = options[:size]
      @icl = options[:icl]
    end
  end
end
