require "spec_helper"

describe "ICL Example 3 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e3.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates the top level module' do
    net = IJTAG.import(file: file).instantiate("SRegP0")
    net.is_a?(IJTAG::Module).should == true
    net.ports.size.should == 10
    net.scan_client.type.should == :client
    net.scan_client.si.should == net.SI
    net.scan_client.so.should == net.SO
    net.scan_client.sel.should == net.SEL
    net.scan_client.se.should == net.SE
    net.scan_client.ce.should == net.CE
    net.scan_client.ue.should == net.UE
    net.client_interfaces[0].should == net.scan_client
    net.sr.is_a?(Origen::Models::ScanRegister).should == true
    net.sr.size.should == 8
    net.di.size.should == 8
  end

  it 'resolves in-line default parameters' do
    net = IJTAG.import(file: file).instantiate("SRegP1")
    net.sr.size.should == 8
    net.di.size.should == 8
    net.do.size.should == 8
  end

  it 'resolves in-line parameter overrides' do
    net = IJTAG.import(file: file).instantiate("SRegP2")
    net.p1.sr.size.should == 3
    net.p1.di.size.should == 3
    net.p1.do.size.should == 3
  end

  it 'resolves top-level parameter overrides' do
    net = IJTAG.import(file: file).instantiate("SRegP1", MSB: 4)
    net.sr.size.should == 5
    net.di.size.should == 5
    net.do.size.should == 5
  end

  it 'resolves parameter overrides with simple math' do
    defn = IJTAG.import(file: file)
    net = defn.instantiate("SReg")
    net.sr.size.should == 8
    net.di.size.should == 8
    net.do.size.should == 8
    net = defn.instantiate("SReg", Size: 6) 
    net.sr.size.should == 6
    net.di.size.should == 6
    net.do.size.should == 6
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("SReg", Size: 3)
    net.sr.size.should == 3
    net.chain_length.should == 3

    # Scan in some data
    net.shift!(1)
    net.shift!(0)
    net.shift!(1)

    net.so.data.should == 1
    net.shift!(1)
    net.so.data.should == 0
    net.shift!(0)
    net.so.data.should == 1
    net.shift!(1)

    # Update DO
    # Peek at internal reg
    net.sr.sr.data.should == 0b101
    # Verify not exposed yet
    net.do.data.should == 0b000
    net.update!
    net.do.data.should == 0b101

    # Capture and shift out some data
    net.di.drive(0b100)
    net.capture!
    net.so.data.should == 0
    net.shift!
    net.so.data.should == 0
    net.shift!
    net.so.data.should == 1
  end
end
