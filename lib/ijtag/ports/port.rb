module IJTAG
  module Ports
    # Represents an I/O port connection on a model
    class Port
      attr_reader :size
      attr_reader :name
      attr_reader :owner

      alias_method :parent, :owner

      def initialize(owner, name, options = {})
        @owner = owner
        @name = name
        @size = options[:size] || 1
      end
    end
  end
end
