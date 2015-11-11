require "spec_helper"

describe "ICL Example 9 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e9.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates all modules' do
    net = IJTAG.import(file: file).instantiate("mux_inline3")
    net.reg3.should be
    net.mux1.should be
    net.mux2.should be
    net.mux3.should be
    net.wi1.should be
    net.wi2.should be
    net.wi3.should be
    net.reg3.do.size.should == 3
  end

  it 'nodes can be tied off to logic levels' do
    net = IJTAG.import(file: file).instantiate("mux_inline3")
    net.reg3.di.inputs[0].value.should == 0
  end

  it 'individual bits of a port can be tied to different nodes' do
    net = IJTAG.import(file: file).instantiate("mux_inline3")
    net.reg3.do[1].path.should == "reg3.DO[1]"
    net.reg3.do[1..0].path.should == "reg3.DO[1:0]"
    net.reg3.do[0].outputs[0].path.should == 'mux1'
    net.reg3.do[1].outputs[0].path.should == 'mux2'
    net.reg3.do[2].outputs[0].path.should == 'mux3'
  end

  it 'scan muxes are modelled accurately'
end
