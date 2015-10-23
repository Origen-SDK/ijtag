require "spec_helper"

describe "ICL Example 2 from the 1687 spec" do

  it "can be parsed to an ast" do
    icl = File.read("#{Origen.root}/examples/e2.icl")
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates a model named "Instrument"' do

  end 

end
