require "spec_helper"

describe "ICL Example 22 from the 1687 spec" do

  def icl_file
    "#{Origen.root}/examples/e22.icl"
  end

  def pdl_file
    "#{Origen.root}/examples/e22.pdl"
  end

  it "can be parsed to an ast" do
    icl = File.read(icl_file)
    ast = icl_parser.parse(icl).to_ast
    pdl = File.read(pdl_file)
    ast = pdl_parser.parse(pdl).to_ast
  end

end
