require "spec_helper"

describe "ICL Example 15 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e15.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'the logic signals work' do
    net = IJTAG.import(file: file).instantiate("Exclusive_broadcast")
    net.chain_length.should == 3
    net.sel.drive(0)
    net.sel1.data.should == 0
    net.sel2.data.should == 0
    net.sel3.data.should == 0
    net.shift!(0b010, size: 3)
    net.update!
    net.sel1.data.should == 0
    net.sel2.data.should == 0
    net.sel3.data.should == 0
    net.sel.drive(1)
    net.sel1.data.should == 0
    net.sel2.data.should == 1
    net.sel3.data.should == 0
    net.chain_length.should == 11
    net.shift!(0b110, size: 11)
    net.update!
    net.sel.drive(1)
    net.sel1.data.should == 1
    net.sel2.data.should == 1
    net.sel3.data.should == 1
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("Exclusive_broadcast")
    net.wi1.so_visible?.should == false
    net.wi2.so_visible?.should == false
    net.wi3.so_visible?.should == false
    net.chain_length.should == 3

    # Verify that we can shift into all 3 modules simultaneously
    net.shift!(0b100, size: 3) # Enable broadcast mode
    net.update!
    net.shift!(0x55, size: 8)
    net.update!
    net.wi1.reg8.sr.data.should == 0x55
    net.wi2.reg8.sr.data.should == 0x55
    net.wi3.reg8.sr.data.should == 0x55

    net.shift!(0, size: 11)
    net.update!
    net.chain_length.should == 3
    net.shift!(0b010, size: 3)
    net.update!
    net.shift!(0xAA, size: 8)
    net.update!
    net.wi1.reg8.sr.data.should == 0x55
    net.wi2.reg8.sr.data.should == 0xAA
    net.wi3.reg8.sr.data.should == 0x55

    # Verify capture is enabled by broadcast selection
    net.wi1.i1.do.drive(0x11)
    net.wi2.i1.do.drive(0x22)
    net.wi3.i1.do.drive(0x33)

    net.shift!(0, size: 11)
    net.update!
    net.shift!(0b100, size: 3) # Enable broadcast mode
    net.update!
    net.capture!
    net.wi1.reg8.sr.sr.data.should == 0x11
    net.wi2.reg8.sr.sr.data.should == 0x22
    net.wi3.reg8.sr.sr.data.should == 0x33
  end
end
