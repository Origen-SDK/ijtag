require "spec_helper"

describe "ICL Example 21 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e21.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'the embedded eTAPC drives the host signals correctly' do
    net = IJTAG.import(file: file).instantiate("Single_eTAP_3WI")

    net.client_tap_interfaces.first.tap_driver.shift_ir do
      net.client_tap_interfaces.first.tap.state.should == :shift_ir
      net.etapc1.client_tap_interfaces.first.tap.state.should == :shift_ir
      net.etapc1.fsm.se.data.should == 1
      net.etapc1.fsm.irsel.data.should == 1
    end

    net.client_tap_interfaces.first.tap_driver.shift_dr do
      net.client_tap_interfaces.first.tap.state.should == :shift_dr
      net.etapc1.client_tap_interfaces.first.tap.state.should == :shift_dr
      net.etapc1.fsm.se.data.should == 1
      net.etapc1.fsm.irsel.data.should == 0
    end
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("Single_eTAP_3WI")

    net.client_interfaces.size.should == 0
    net.client_tap_interfaces.size.should == 1
    net.etapc1.scan_host.type.should == :host

    net.sel.drive(0)
    net.chain_length.should == 0
    net.sel.drive(1)
    net.chain_length.should == 1

    net.tap_driver.shift_ir do
      net.chain_length.should == 3
    end
    net.chain_length.should == 1

    net.shift_ir!(0b001, size: 3)
    net.etapc1.ir.data.should == 0b001

    net.chain_length.should == 24
    net.shift_ir!(0b000, size: 3)
    net.chain_length.should == 1

    net.shift_ir!(0b001, size: 3)
    net.chain_length.should == 24
    net.shift_dr!(0x11_22_33, size: 24)
    net.chain_length.should == 24
    net.wi1.reg8.sr.data.should == 0x11
    net.wi2.reg8.sr.data.should == 0x22
    net.wi3.reg8.sr.data.should == 0x33

    net.wi1.i1.do.drive(0xF1)
    net.wi2.i1.do.drive(0xF2)
    net.wi3.i1.do.drive(0xF3)
    
    #net.shift_dr!(0, expect: 0xF1_F2_F3, size: 24).should == true
    net.shift_dr!(0, expect: 0x11_22_33, size: 24).should == true
  end
end
