require "spec_helper"

describe "ICL Example 17 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e17.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("Branched_SI")

    net.client_interfaces.size.should == 2

    net.chain_length.should == 16
    net.chain_length(so: net.so2).should == 8
  end
end
