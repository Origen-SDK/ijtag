require 'origen'
require_relative '../config/application.rb'

ext = File.join(File.dirname(__FILE__), 'ijtag.so')
require 'ijtag.so' if File.exist?(ext)

module IJTAG
  class << self
    # Imports an ICL network definition and returns an instance of
    # IJTAG::NetworkDefinition
    def import(*args)
      IJTAG::NetworkDefinition.new(*args)
    end
  end
end
