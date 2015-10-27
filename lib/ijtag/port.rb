module IJTAG
  # Represents an I/O port connection on a model
  class Port
    include Origen::Model

    attr_reader :size
    attr_reader :icl
    attr_reader :network
    attr_reader :type

    def initialize(options = {})
      @size = options[:size] || 1
      @icl = options[:icl]
      @network = options[:network]
      @type = options[:type]
    end

    # Returns the downstream Port object that the current port connects to
    def to
      # Need some logic to handle the ScanRegister virtual ports
      if path =~ /\.update$/ && parent.is_a?(ScanRegister)
        lpath = path.sub(/.update$/, '')
      elsif path =~ /\.so$/ && parent.is_a?(ScanRegister)
        lpath = path.sub(/.so$/, '[0]')
      else
        lpath = path
      end
      if p = network.netlist.outputs[lpath]
        eval "network.#{p}"
      end
    end
    alias_method :output, :to

    # Returns the upstream Port object that is connected to the current port
    def from
      if p = network.netlist.inputs[path]
        port = eval "network.#{p}"
        # Need some logic to handle the ScanRegister virtual ports
        if port.is_a?(ScanRegister)
          port.update
        elsif port.is_a?(Origen::Registers::BitCollection) && port.position == 0 &&
              port.parent.try(:parent).is_a?(ScanRegister)
          port.parent.parent.so
        else
          port
        end
      end
    end
    alias_method :input, :from
  end
end
