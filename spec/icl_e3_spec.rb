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
    net = IJTAG.import(file: file).instantiate("SReg")
    net.is_a?(IJTAG::Module).should == true
    net.ports.size.should == 10
    net.scan_interfaces.size.should == 1
    net.scan_registers.size.should == 1
    net.sr.is_a?(IJTAG::ScanRegister).should == true
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
    net = defn.instantiate("SRegP3")
    net.sr.size.should == 8
    net.di.size.should == 8
    net.do.size.should == 8
    net = defn.instantiate("SRegP3", Size: 6) 
    net.sr.size.should == 6
    net.di.size.should == 6
    net.do.size.should == 6
  end
end
