require 'origen_jtag'
module IJTAG
  class TAPDriver
    include Origen::Model
    include OrigenJTAG::TAPController

    attr_reader :network

    def initialize(network)
      @network = network
      @state = :unknown
    end

    def log(msg, options = {})
    end

    def tms!(data)
      network.tms.drive(data)
      network.clock!
    end
  end
end
