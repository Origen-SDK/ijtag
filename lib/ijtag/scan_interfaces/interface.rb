module IJTAG
  module ScanInterfaces
    class Interface
      attr_reader :parent, :port_names, :id
      alias_method :name, :id

      def initialize(id, parent)
        @parent = parent
        @id = id
        @port_names = []
      end

      def add_port(name)
        @port_names << name
      end

      def type
        @type ||= begin
          if port_map[:SelectPort] || port_map[:ShiftEnPort]
            :client
          elsif port_map[:ToSelectPort] || port_map[:ToShiftEnPort]
            :host
          elsif port_map[:TMSPort]
            :client_tap
          elsif port_map[:ToTMSPort]
            :host_tap
          else
            fail "Unidentified Scan interface #{id}"
          end
        end
      end

      def port_map
        @port_map ||= begin
          map = {}
          port_names.each do |name|
            p = parent.send(name)
            if map[p.type]
              fail "Interface contains multiple ports of type #{p.type}"
            else
              map[p.type] = p
            end
          end
          map
        end
      end

      def shift!(val = nil, options = {})
        val, options = nil, val if val.is_a?(Hash)
        miscompare = false
        with_select do
          with_shift do
            (options[:size] || 1).times do |i|
              if options[:expect]
                unless options[:expect][i] == so.data
                  miscompare = true
                end
              end
              si.drive(val[i]) if val
              parent.clock!
            end
          end
        end
        if options[:expect]
          !miscompare
        end
      end

      def update!
        with_select do
          with_update do
            parent.clock!
          end
        end
      end

      def capture!
        with_select do
          with_capture do
            parent.clock!
          end
        end
      end

      def si
        port_map[:ScanInPort]
      end

      def so
        port_map[:ScanOutPort]
      end

      def sel
        find_port(:SelectPort, :client)
      end

      def se
        find_port(:ShiftEnPort, :client, true)
      end

      def ce
        find_port(:CaptureEnPort, :client, true)
      end

      def ue
        find_port(:UpdateEnPort, :client, true)
      end

      def rst
        find_port(:ResetPort, :client)
      end

      def tck
        find_port(:TCKPort, [:client, :client_tap])
      end

      def to_sel
        find_port(:ToSelectPort, :host)
      end

      def to_se
        find_port(:ToShiftEnPort, :host, true)
      end

      def to_ce
        find_port(:CaptureEnPort, :host, true)
      end

      def to_ue
        find_port(:UpdateEnPort, :host, true)
      end

      def to_rst
        find_port(:ToResetPort, :host)
      end

      def to_tck
        find_port(:ToTCKPort, [:host, :host_tap])
      end

      def tms
        find_port(:TMSPort, :client_tap)
      end

      def trst
        find_port(:TRSTPort, :client_tap)
      end

      def to_tms
        find_port(:ToTMSPort, :host_tap)
      end

      def to_trst
        find_port(:ToTRSTPort, :host_tap)
      end

      private

      def find_port(port_type, interface_type, consider_parent = false)
        if [interface_type].flatten.include?(type)
          port_map[port_type] || begin
            if consider_parent
              p = parent.ports.find { |n, p| p.type == port_type }
              p[1] if p
            end
          end
        else
          fail "#{type} Scan interfaces do not have a #{port_type}!"
        end
      end

      def with_select
        sel.drive(1)
        yield
        sel.drive(0)
      end

      def with_capture
        ce.drive(1)
        yield
        ce.drive(0)
      end

      def with_shift
        se.drive(1)
        yield
        se.drive(0)
      end

      def with_update
        ue.drive(1)
        yield
        ue.drive(0)
      end
    end
  end
end
