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
    net.chain_length.should == 1
    net.shift!(1)
    net.update!
    net.chain_length.should == 10
  end
end
