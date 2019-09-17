require "spec_helper"

describe "ICL Example 18 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e18.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("Branched_then_merged")

    net.chain_length.should == 17
    net.shift!((0x55AA << 1) | 1, size: 17)
    net.update!
    net.wi1.reg8.sr.data.should == 0x55
    net.wi2.reg8.sr.data.should == 0xAA
    net.wi3.reg8.sr.data.should == 0
    net.shift!(0x11, size: 8)
    net.update!
    net.wi1.reg8.sr.data.should == 0x55
    net.wi2.reg8.sr.data.should == 0xAA
    net.wi3.reg8.sr.data.should == 0x11
  end
end
