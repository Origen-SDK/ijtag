require "spec_helper"

describe "The TAP driver and model" do

  class B1
    include Origen::Model

    def initialize
      port :tms

      sub_block :tap, class_name: "IJTAG::TAP"

      tms.connect_to tap.tms
    end

    def tap
      sub_blocks[:tap]
    end
  end

  it "The model is in sync with the driver" do
    b = B1.new
    driver = IJTAG::TAPDriver.new(b)
    driver.reset
    b.tap.state.should == :reset

    driver.shift_ir do
      b.tap.state.should == :shift_ir
      b.tap.shift.data.should == 1
      b.tap.ir_sel.data.should == 1
    end

    driver.shift_dr do
      b.tap.state.should == :shift_dr
      b.tap.shift.data.should == 1
      b.tap.ir_sel.data.should == 0
    end
  end
end
