module IJTAG
  class TAP
    include Origen::Model

    attr_reader :state

    def initialize
      @state = :reset

      # These ports assert whenever the TAP is in the given state, one-hot
      port :capture, size: 1
      port :shift, size: 1
      port :update, size: 1
      port :ir_sel, size: 1

      port :tms, size: 1

      capture.connect_to { (state == :capture_dr || state == :capture_ir) ? 1 : 0 }
      shift.connect_to { (state == :shift_dr || state == :shift_ir) ? 1 : 0 }
      update.connect_to { (state == :update_dr || state == :update_ir) ? 1 : 0 }
      ir_sel.connect_to { (state == :capture_ir || state == :shift_ir || state == :update_ir) ? 1 : 0 }
    end

    def clock_prepare
      @tms = tms.data
    end

    def clock_apply
      case state
      when :reset
        @state = @tms == 0 ? :idle : :reset
      when :idle
        @state = @tms == 0 ? :idle : :select_dr
      when :select_dr
        @state = @tms == 0 ? :capture_dr : :select_ir
      when :capture_dr
        @state = @tms == 0 ? :shift_dr : :exit1_dr
      when :shift_dr
        @state = @tms == 0 ? :shift_dr : :exit1_dr
      when :exit1_dr
        @state = @tms == 0 ? :pause_dr : :update_dr
      when :pause_dr
        @state = @tms == 0 ? :pause_dr : :exit2_dr
      when :exit2_dr
        @state = @tms == 0 ? :shift_dr : :update_dr
      when :update_dr
        @state = @tms == 0 ? :idle : :select_dr
      when :select_ir
        @state = @tms == 0 ? :capture_ir : :reset
      when :capture_ir
        @state = @tms == 0 ? :shift_ir : :exit1_ir
      when :shift_ir
        @state = @tms == 0 ? :shift_ir : :exit1_ir
      when :exit1_ir
        @state = @tms == 0 ? :pause_ir : :update_ir
      when :pause_ir
        @state = @tms == 0 ? :pause_ir : :exit2_ir
      when :exit2_ir
        @state = @tms == 0 ? :shift_ir : :update_ir
      when :update_ir
        @state = @tms == 0 ? :idle : :select_dr
      end
    end
  end
end
