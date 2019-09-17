require "spec_helper"

describe "ICL Example 19 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e19.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("WSP1500")

    net.swir.drive(0)
    net.chain_length.should == 1
    net.swir.drive(1)
    net.chain_length.should == 2
    net.shift!(0b01, size: 2)
    net.update!
    net.swir.drive(0)
    net.chain_length.should == 8
    net.shift!(0x11, size: 8)
    net.update!

    net.wi1.reg8.sr.data.should == 0x11
    net.wi2.reg8.sr.data.should == 0x0
    net.wi3.reg8.sr.data.should == 0x0

    net.swir.drive(1)
    net.shift!(0b01, size: 2)
    net.update!
    net.swir.drive(0)
    net.chain_length.should == 8

    net.wi1.reg8.sr.data.should == 0x11
    net.wi2.reg8.sr.data.should == 0x0
    net.wi3.reg8.sr.data.should == 0x0
  end
end
