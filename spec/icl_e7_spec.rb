require "spec_helper"

describe "ICL Example 7 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e7.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates all modules' do
    net = IJTAG.import(file: file).instantiate("Single_SIB_3WI")
    net.sib1.should be
    net.wi1.should be
    net.wi2.should be
    net.wi3.should be
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("Single_SIB_3WI")
    net.chain_length.should == 1
    net.shift!(1)
    net.update!
    net.chain_length
    net.chain_length.should == 25
    net.shift!(0, size: 25)
    net.update!
    net.chain_length.should == 1
  end
end
