module IJTAG
  # Provides APIs to model port connections between models, this will likely
  # become part of Origen core in future
  module Ports
    def ports
      @ports ||= {}
    end

    def add_port(name, options = {})
      ports[name] = Port.new(self, name, options)
    end
  end
end
