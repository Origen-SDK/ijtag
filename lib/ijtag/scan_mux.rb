module IJTAG
  class ScanMux
    include Origen::Model

    attr_reader :icl
    attr_reader :network

    def initialize(options = {})
      @icl = options[:icl]
      @network = options[:network]
    end
  end
end
