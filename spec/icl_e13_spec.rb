require "spec_helper"

describe "ICL Example 13 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e13.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("Exclusive")
    net.wi1.so_visible?.should == false
    net.wi2.so_visible?.should == false
    net.wi3.so_visible?.should == false
    net.chain_length.should == 2
    net.shift!(0b01, size: 2)
    net.update!
    net.chain_length.should == 10
    net.wi1.so_visible?.should == true
    net.wi2.so_visible?.should == false
    net.wi3.so_visible?.should == false
    net.shift!(0b10, size: 10)
    net.update!
    net.chain_length.should == 10
    net.wi1.so_visible?.should == false
    net.wi2.so_visible?.should == true
    net.wi3.so_visible?.should == false
    net.shift!(0b11, size: 10)
    net.update!
    net.chain_length.should == 10
    net.wi1.so_visible?.should == false
    net.wi2.so_visible?.should == false
    net.wi3.so_visible?.should == true

    # Verify that the module selection is implied and inhibits shift
    net.shift!(0, size: 10)
    net.update!
    net.chain_length.should == 2
    net.shift!(0xFFFF, size: 16)
    net.wi1.reg8.sr.sr.data.should == 0
    net.wi2.reg8.sr.sr.data.should == 0
    net.wi3.reg8.sr.sr.data.should == 0
    net.shift!(0b01, size: 2)
    net.update!
    net.chain_length.should == 10
    net.shift!(0xFFFF, size: 16)
    net.wi1.reg8.sr.sr.data.should == 0xFF
    net.wi2.reg8.sr.sr.data.should == 0
    net.wi3.reg8.sr.sr.data.should == 0

    net.shift!(0b10, size: 10)
    net.update!
    net.chain_length.should == 10
    net.shift!(0xFFFF, size: 16)
    net.wi1.reg8.sr.sr.data.should == 0
    net.wi2.reg8.sr.sr.data.should == 0xFF
    net.wi3.reg8.sr.sr.data.should == 0

    net.shift!(0b11, size: 10)
    net.update!
    net.chain_length.should == 10
    net.shift!(0xFFFF, size: 16)
    net.wi1.reg8.sr.sr.data.should == 0
    net.wi2.reg8.sr.sr.data.should == 0
    net.wi3.reg8.sr.sr.data.should == 0xFF

    # Verify capture is inhibited by implied selection
    net.wi1.i1.do.drive(0x11)
    net.wi2.i1.do.drive(0x22)
    net.wi3.i1.do.drive(0x33)

    net.shift!(0, size: 10)
    net.update!
    net.chain_length.should == 2
    net.capture!
    net.wi1.reg8.sr.sr.data.should == 0
    net.wi2.reg8.sr.sr.data.should == 0
    net.wi3.reg8.sr.sr.data.should == 0

    net.shift!(0b10, size: 2)
    net.update!
    net.chain_length.should == 10
    net.capture!
    net.wi1.reg8.sr.sr.data.should == 0
    net.wi2.reg8.sr.sr.data.should == 0x22
    net.wi3.reg8.sr.sr.data.should == 0
  end
end
