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
  end

  it 'accepts in-line default parameters' do
    net = IJTAG.import(file: file).instantiate("SRegParam")
    net.sr.size.should == 8
  end
end
