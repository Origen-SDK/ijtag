module IJTAG
  class ScanRegister < Origen::Models::ScanRegister
    # Returns true if the scan register is an IR register, this is determined
    # by looking at the context of its local connections
    def ir?
      !!ir_sel
    end

    def ir_sel
      return @ir_sel if defined? @ir_sel
      @ir_sel = begin
        if mux = mux_on_so
          mux.select.ports.find { |p| p.try(:type) == :ToIRSelectPort }
        end
      end
    end

    def mux_on_so
      return @mux_on_so if defined? @mux_on_so
      @mux_on_so = begin
        if p = so.ports.find { |p| p.parent.is_a?(Origen::Models::Mux) && p.id.to_s =~ /^input\d+$/ }
          p.parent
        end
      end
    end

    def mode
      # Make IR registers unselected when their IR select is low
      if ir?
        if ir_sel.data == 1
          super
        else
          undefined
        end
      else
        super
      end
    end
  end
end
