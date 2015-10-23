module IJTAG
  class Network
    include Origen::Model

    alias_method :instruments, :sub_blocks
  end
end
