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

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("WrappedInstr")
    



    net.si.outputs[0].path.should == "reg8.SI"
    net.reg8.si.inputs[0].path.should == "SI"
    net.so.inputs[0].path.should == "reg8.SO"
    net.reg8.so.outputs[0].path.should == "SO"
    net.reg8.di.inputs[0].path.should == "I1.DO"
    net.i1.do.outputs[0].path.should == "reg8.DI"
    net.reg8.do.outputs[0].path.should == "I1.DI"
    net.i1.di.inputs[0].path.should == "reg8.DO"
  end
end
