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
    net.i1.module_name.should == "Instrument"
    net.i1.instance_name.should == "I1"
    net.reg8.module_name.should == "SReg"
    net.reg8.instance_name.should == "reg8"
  end

  it 'the connections are hooked up'
end
