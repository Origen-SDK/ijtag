require "spec_helper"

describe "ICL Example 11 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e11.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("Nested_SIB_3WI")
    # These are some tests to verify that the chain_length method
    # puts the chain contents back as they were
    net.wi1.reg8.sr.sr.write(0x15)
    net.wi1.reg8.sr.sr.data.should == 0x15
    net.chain_length.should == 1
    net.wi1.reg8.sr.sr.data.should == 0x15
    net.wi1.reg8.sr.sr.write(0x0)

    # Now test the actual model
    net.shift!(1)
    net.update!
    net.chain_length.should == 10
    net.shift!(0b11, size: 10)
    net.update!
    net.chain_length.should == 19
    net.shift!(0b111, size: 19)
    net.update!
    net.chain_length.should == 27
    net.shift!(0, size: 27)
    net.update!
    net.chain_length.should == 1
    net.to_graph.lookup["SI"].to_img
  end
end
