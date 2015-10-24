require 'ijtag/ports'
module IJTAG
  class Network
    include Origen::Model
    include IJTAG::Ports

    alias_method :instruments, :sub_blocks
  end
end
