require 'ijtag/ports'
module IJTAG
  # Corresponds to an ICL module instance, block is chosen as the name instead
  # of module since the latter means something in Ruby and is not a valid
  # class name
  class Module
    include Origen::Model
    include IJTAG::Ports
    include IJTAG::Aliases
    include IJTAG::Enumerations
  end
end
