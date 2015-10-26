require "spec_helper"

describe "ICL Example 4 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e4.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates the top level module' do
    net = IJTAG.import(file: file).instantiate("WrappedInstr")
    #net.is_a?(IJTAG::Module).should == true
    #net.ports.size.should == 10
    #net.scan_interfaces.size.should == 1
    #net.scan_registers.size.should == 1
    #net.sr.is_a?(IJTAG::ScanRegister).should == true
    #net.sr.size.should == 8
    #net.di.size.should == 8
  end
end
