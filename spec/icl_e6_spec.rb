require "spec_helper"

describe "ICL Example 6 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e6.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates all modules' do
    net = IJTAG.import(file: file).instantiate("SIB_mux_pre")
  end

  it 'the connections are hooked up' do
    net = IJTAG.import(file: file).instantiate("SIB_mux_pre")
  end
end
