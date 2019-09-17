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
    net.reg3.di.data.should == 0
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("mux_inline3")
    net.chain_length.should == 3
    net.shift!(0b001, size: 3)
    net.update!
    net.chain_length.should == 3 + 8
    net.shift!(0b111, size: 11)
    net.update!
    net.chain_length.should == 3 + (8 * 3)
  end
end
