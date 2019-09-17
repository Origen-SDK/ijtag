require "spec_helper"

describe "ICL Example 16 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e16.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("Broadcast")

    net.chain_length.should == 25
    # Enable broadcast
    net.shift!(1, size: 25)
    net.update!
    net.chain_length.should == 9

    net.shift!((0x55 << 1), size: 9)
    net.update!

    net.wi1.reg8.sr.data.should == 0x55
    net.wi2.reg8.sr.data.should == 0x55
    net.wi3.reg8.sr.data.should == 0x55
    net.chain_length.should == 25

    net.shift!(0, expect: 0x555555 << 1).should == true
  end
end
