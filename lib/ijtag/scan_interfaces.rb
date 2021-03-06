module IJTAG
  module ScanInterfaces
    def client_interfaces
      @client_interfaces ||= begin
        i = scan_interfaces.select { |k, v| v.type == :client }.values
        if i.empty?
          p = ports.by_type.keys
          if p.include?('ScanInPort') && p.include?('ScanOutPort') &&
             (p.include?('SelectPort') || p.include?('ShiftEnPort'))
            int = Interface.new(:undeclared_client_interface, self)
            int.add_port(ports.by_type['ScanInPort'].first.name)
            int.add_port(ports.by_type['ScanOutPort'].first.name)
            if ports.by_type['SelectPort']
              int.add_port(ports.by_type['SelectPort'].first.name)
            end
            if ports.by_type['ShiftEnPort']
              int.add_port(ports.by_type['ShiftEnPort'].first.name)
            end
            i << int
          end
        end
        i
      end
    end

    def client_tap_interfaces
      @client_tap_interfaces ||= begin
        i = scan_interfaces.select { |k, v| v.type == :client_tap }.values
        if i.empty?
          p = ports.by_type.keys
          if p.include?('TmsPort')
            int = Interface.new(:undeclared_client_tap_interface, self)
            int.add_port(ports.by_type['ScanInPort'].first.name) if p.include?('ScanInPort')
            int.add_port(ports.by_type['ScanOutPort'].first.name) if p.include?('ScanOutPort')
            if ports.by_type['TmsPort']
              int.add_port(ports.by_type['TmsPort'].first.name)
            end
            i << int
          end
        end
        i
      end
    end

    def host_interfaces
      @host_interfaces ||= begin
        i = scan_interfaces.select { |k, v| v.type == :host }.values
        if i.empty?
          p = ports.by_type.keys
          if p.include?('ScanInPort') && p.include?('ScanOutPort') &&
             (p.include?('ToSelectPort') || p.include?('ToShiftEnPort'))
            int = Interface.new(:undeclared_host_interface, self)
            int.add_port(ports.by_type['ScanInPort'].first.name)
            int.add_port(ports.by_type['ScanOutPort'].first.name)
            if ports.by_type['ToSelectPort']
              int.add_port(ports.by_type['ToSelectPort'].first.name)
            end
            if ports.by_type['ToShiftEnPort']
              int.add_port(ports.by_type['ToShiftEnPort'].first.name)
            end
            i << int
          end
        end
        i
      end
    end

    def add_scan_interface(name)
      lower_case_alias = name.to_s.symbolize
      unless lower_case_alias == name.to_sym
        define_singleton_method lower_case_alias do
          send(name)
        end
      end
      if scan_interfaces[lower_case_alias]
        fail "Duplicate definitions of scan interface #{name}"
      else
        scan_interfaces[lower_case_alias] = Interface.new(lower_case_alias, self)
      end
    end

    def method_missing(method, *args, &block)
      if scan_interfaces.key?(method.to_s.symbolize)
        s = scan_interfaces[method.to_s.symbolize]
        define_singleton_method "#{method}" do
          s
        end
        s
      else
        super
      end
    end

    def respond_to?(sym)
      scan_interfaces.key?(sym.to_s.symbolize) || super(sym)
    end

    def scan_interfaces
      @scan_interfaces ||= ScanInterfaceCollection.new
    end
  end
end
