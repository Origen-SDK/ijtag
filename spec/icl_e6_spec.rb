require "spec_helper"

describe "ICL Example 6 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e6.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates all modules' do
    net = IJTAG.import(file: file).instantiate("SIB_mux_pre")
    net.sr.should be
    net.SIBmux.should be
  end

  it 'the mux input table is correct' do
    net = IJTAG.import(file: file).instantiate("SIB_mux_pre")
    net.sibmux.input_map.should == { 0 => "SI", 1 => "fromSO" }
  end

  it 'the connections are hooked up' do
    net = IJTAG.import(file: file).instantiate("SIB_mux_pre")
    net.so.inputs[0].path.should == "SR"
    net.sr.so[0].path.should == "SO"
    net.si.outputs.size.should == 2
    net.si.outputs.include?(net.toSI).should == true
    net.si.outputs.include?(net.sibmux).should == true
    net.toSI.inputs[0].path.should == "SI"
    net.sr.u[0].path.should == "SIBmux"
    net.sr.c[0].path.should == "SR"
    net.fromSO.outputs[0].path.should == "SIBmux"
    net.sibmux.inputs[0][0].path.should == "SI"
    net.sibmux.inputs[1][0].path.should == "fromSO"
  end
end
