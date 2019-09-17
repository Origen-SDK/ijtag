require 'ijtag.so'
require 'origen'
require_relative '../config/application.rb'
module IJTAG
  class << self
    # Imports an ICL network definition and returns an instance of
    # IJTAG::NetworkDefinition
    def import(*args)
      IJTAG::NetworkDefinition.new(*args)
    end
  end
end
