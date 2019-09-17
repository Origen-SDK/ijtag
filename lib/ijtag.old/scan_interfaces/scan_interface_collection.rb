module IJTAG
  module ScanInterfaces
    class ScanInterfaceCollection < ::Hash
      def inspect
        map { |k, _v| k }.inspect
      end
    end
  end
end
