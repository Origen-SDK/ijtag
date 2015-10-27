module IJTAG
  class ScanRegister
    include Origen::Model

    attr_reader :size
    attr_reader :icl
    attr_reader :network

    def initialize(options = {})
      @size = options[:size]
      @icl = options[:icl]
      @network = options[:network]

      reg :dr, 0, size: size do |reg|
        reg.bit (size - 1)..0, :data
      end

      # Virtual ports
      sub_block :capture, class_name: 'Port', size: size, network: network
      sub_block :update, class_name: 'Port', size: size, network: network
      sub_block :si, class_name: 'Port', size: 1, network: network
      sub_block :so, class_name: 'Port', size: 1, network: network
    end

    # Proxy all other methods to the register object, this implements things
    # like network.sr[0] which will return the bit 0 object
    def method_missing(method, *args, &block)
      if reg(:dr).respond_to?(method)
        reg(:dr).send(method, *args, &block)
      else
        super
      end
    end

    def respond_to?(method)
      # This if is a bit of a hack since Origen seems to call respond_to? before
      # the dr reg is instantiated
      if has_reg?(:dr)
        super || reg(:dr).respond_to?(method)
      else
        super
      end
    end
  end
end
