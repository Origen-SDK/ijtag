module IJTAG
  module Ports
    # Represents an I/O port connection on a model
    class Port
      attr_reader :width
      attr_reader :name
      attr_reader :owner

      alias :parent :owner

      def initialize(owner, name, options={})
        @owner = owner
        @name = name
      end
    end
  end
end
