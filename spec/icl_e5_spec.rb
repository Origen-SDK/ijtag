require "spec_helper"

describe "ICL Example 5 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e5.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates all modules' do
    net = IJTAG.import(file: file).instantiate("Daisy_3WI")
    net.wi1.should be
    net.wi1.i1.should be
    net.wi1.reg8.should be
    net.wi2.should be
    net.wi2.i1.should be
    net.wi2.reg8.should be
    net.wi3.should be
    net.wi3.i1.should be
    net.wi3.reg8.should be
    # Verify that child modules are unique instances
    net.wi1.i1.object_id.should_not == net.wi2.i1.object_id
    net.wi1.reg8.object_id.should_not == net.wi3.reg8.object_id
  end

  it 'the connections are hooked up' do
    net = IJTAG.import(file: file).instantiate("Daisy_3WI")
    net.si.outputs[0].path.should == "WI1.SI"
    net.wi1.si.inputs[0].path.should == "SI"
    net.wi1.so.outputs[0].path.should == "WI2.SI"
    net.wi2.si.inputs[0].path.should == "WI1.SO"
    net.wi2.so.outputs[0].path.should == "WI3.SI"
    net.wi3.si.inputs[0].path.should == "WI2.SO"
    net.wi3.so.outputs[0].path.should == "SO"
    net.so.inputs[0].path.should == "WI3.SO"

    # Verify a couple of deep connections
    net.wi1.reg8.do.outputs[0].path.should == "WI1.I1.DI"
    net.wi3.reg8.sr.si[0].path.should == "WI3.reg8.SI"

  end
end
