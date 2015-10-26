module IJTAG
  class ScanRegister
    include Origen::Model

    attr_reader :size
    attr_reader :ast

    def initialize(options={})
      @size = options[:size]
      @ast = options[:ast]
    end
  end
end
