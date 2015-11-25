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

    # Simulate the various TAP states


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

    # Simulate the TAP control going into shift IR state
    net.etapc1.fsm.irsel.drive(1)
    net.chain_length.should == 3
    net.shift_ir!(0b001, size: 3)
    net.etapc1.ir.data.should == 0b001
    
  end
end
