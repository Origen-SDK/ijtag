require "spec_helper"

describe "ICL Example 8 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e8.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates all modules' do
    net = IJTAG.import(file: file).instantiate("Multiple_SIB_3WI")
    net.sib1.should be
    net.sib2.should be
    net.sib3.should be
    net.wi1.should be
    net.wi2.should be
    net.wi3.should be
  end
end
