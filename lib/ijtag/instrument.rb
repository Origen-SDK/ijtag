require 'ijtag/ports'
module IJTAG
  class Instrument
    include Origen::Model
    include IJTAG::Ports
  end
end
