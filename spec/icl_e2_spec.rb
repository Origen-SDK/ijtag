require "spec_helper"

describe "ICL Example 2 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e2.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates a model named "Instrument"' do
    network = IJTAG.icl_to_model(file: file)
    network.is_a?(IJTAG::Network).should == true
  end 

end
