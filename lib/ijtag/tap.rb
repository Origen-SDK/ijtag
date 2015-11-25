module IJTAG
  class TAP
    include Origen::Model

    attr_reader :network
    attr_reader :state

    def initialize(network)
      @network = network
      @state = :reset

      # These ports assert whenever the TAP is in the given state, one-hot
      port :capture_dr, size: 1
      port :shift_dr, size: 1
      port :update_dr, size: 1
      port :capture_ir, size: 1
      port :shift_ir, size: 1
      port :update_ir, size: 1
      port :idle, size: 1

      port :tms, size: 1

      capture_dr.connect_to { state == :capture_dr ? 1 : 0 }
      shift_dr.connect_to { state == :shift_dr ? 1 : 0 }
      update_dr.connect_to { state == :update_dr ? 1 : 0 }
      capture_ir.connect_to { state == :capture_ir ? 1 : 0 }
      shift_ir.connect_to { state == :shift_ir ? 1 : 0 }
      update_ir.connect_to { state == :update_ir ? 1 : 0 }
    end

    def before_clock
      @tms = tms.data
    end

    def apply_clock
      case state
      when :reset
        state = @tms == 0 ? :idle : :reset
      when :idle
        state = @tms == 0 ? :select_dr : :idle
      when :select_dr
        state = @tms == 0 ? :capture_dr : :select_ir
      when :capture_dr
        state = @tms == 0 ? :shift_dr : :exit1_dr
      when :shift_dr
        state = @tms == 0 ? :shift_dr : :exit1_dr
      when :exit1_dr
        state = @tms == 0 ? :pause_dr : :update_dr
      when :pause_dr
        state = @tms == 0 ? :pause_dr : :exit2_dr
      when :exit2_dr
        state = @tms == 0 ? :shift_dr : :update_dr
      when :update_dr
        state = @tms == 0 ? :idle : :select_dr
      when :select_ir
        state = @tms == 0 ? :capture_ir : :reset
      when :capture_ir
        state = @tms == 0 ? :shift_ir : :exit1_ir
      when :shift_ir
        state = @tms == 0 ? :shift_ir : :exit1_ir
      when :exit1_ir
        state = @tms == 0 ? :pause_ir : :update_ir
      when :pause_ir
        state = @tms == 0 ? :pause_ir : :exit2_ir
      when :exit2_ir
        state = @tms == 0 ? :shift_ir : :update_ir
      when :update_ir
        state = @tms == 0 ? :idle : :select_dr
      end
    end
  end
end
