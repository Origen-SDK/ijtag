module IJTAG
  require 'delegate'
  class SizedNumber < Delegator
    def initialize(obj, options = {})
      @obj = obj
      @size = options[:size]
    end

    def __getobj__
      @obj
    end

    def size
      @size
    end
  end
end
