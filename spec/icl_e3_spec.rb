require "spec_helper"

describe "ICL Example 3 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e3.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end
end
