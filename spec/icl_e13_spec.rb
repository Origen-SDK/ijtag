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
    net.wi1.reg8.sr.sr.data.should == 0
    net.wi2.reg8.sr.sr.data.should == 0
    net.wi3.reg8.sr.sr.data.should == 0
  end
end
