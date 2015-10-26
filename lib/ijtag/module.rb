require 'ijtag/ports'
module IJTAG
  # Corresponds to an ICL module instance
  class Module
    include Origen::Model
    include IJTAG::Ports
    include IJTAG::Aliases
    include IJTAG::Enumerations
  end
end
