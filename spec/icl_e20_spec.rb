require "spec_helper"

describe "ICL Example 20 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e20.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("WSP1500_SWIR")

    # SWIR resets to 1
    net.swir.data.should == 1
    net.chain_length.should == 3
    net.shift!(0, size: 3)
    net.update!
    net.chain_length.should == 2
    net.shift!(1)
    net.update!
    net.chain_length.should == 3
    net.shift!(0b010, size: 3)
    net.update!
    net.chain_length.should == 9
    net.shift!(0x122, size: 9)
    net.update!

    net.wi1.reg8.sr.data.should == 0x0
    net.wi2.reg8.sr.data.should == 0x22
    net.wi3.reg8.sr.data.should == 0x0

    net.update!
    net.chain_length.should == 3
    net.shift!(0b011, size: 3)
    net.update!
    net.chain_length.should == 9
    net.shift!(0x33, size: 9)
    net.update!

    net.wi1.reg8.sr.data.should == 0x0
    net.wi2.reg8.sr.data.should == 0x22
    net.wi3.reg8.sr.data.should == 0x33
  end
end
