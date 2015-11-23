require "spec_helper"

describe "ICL Example 10 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e10.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates all modules' do
    net = IJTAG.import(file: file).instantiate("mux_remote3")
    remote = IJTAG.import(file: file).instantiate("remote_control")
    remote.reg3.do.size.should == 3
  end
end
