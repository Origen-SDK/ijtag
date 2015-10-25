require 'ijtag/ports'
module IJTAG
  class Instrument
    include Origen::Model
    include IJTAG::Ports
    include IJTAG::Aliases
    include IJTAG::Enumerations
  end
end
