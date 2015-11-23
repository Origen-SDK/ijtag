module IJTAG
  module ScanInterfaces
    def client_interfaces
      @client_interfaces ||= begin
        i = scan_interfaces.select { |k, v| v.type == :client }.values
        if i.empty?
          p = ports.by_type.keys
          if p.include?('ScanInPort') && p.include?('ScanOutPort') &&
             (p.include?('SelectPort') || p.include?('ShiftEnPort'))
            int = Interface.new(:default, self)
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
