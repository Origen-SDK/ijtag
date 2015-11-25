require 'origen_jtag'
module IJTAG
  class TAPDriver
    include Origen::Model
    include OrigenJTAG::TAPController

    attr_reader :network

    def initialize(network)
      @network = network
      @state = :unknown

      port :tms, size: 1
    end

    def log(msg, options = {})
    end

    def tms!(data)
      tms.drive(data)
      network.clock!
    end
  end
end
