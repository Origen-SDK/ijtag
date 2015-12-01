require "spec_helper"

describe "ICL Example 8 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e8.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates all modules' do
    net = IJTAG.import(file: file).instantiate("Multiple_SIB_3WI")
    net.sib1.should be
    net.sib2.should be
    net.sib3.should be
    net.wi1.should be
    net.wi2.should be
    net.wi3.should be
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("Multiple_SIB_3WI")
    net.chain_length.should == 3
    net.shift!(0b101, size: 3)
    net.update!
    net.chain_length.should == 19

    net.wi1.i1.do.drive(0x11)
    net.wi2.i1.do.drive(0x22)
    net.wi3.i1.do.drive(0x33)

    net.capture!
    net.chain_length.should == 19
    net.capture!
    net.shift!
    net.shift!(size: 8, expect: 0x33).should == true
    net.shift!
    net.shift!
    net.shift!(size: 8, expect: 0x11).should == true
    net.to_graph.lookup["SI"].to_img
  end
end
