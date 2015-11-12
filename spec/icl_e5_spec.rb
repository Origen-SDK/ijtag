require "spec_helper"

describe "ICL Example 5 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e5.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates all modules' do
    net = IJTAG.import(file: file).instantiate("Daisy_3WI")
    net.wi1.should be
    net.wi1.i1.should be
    net.wi1.reg8.should be
    net.wi2.should be
    net.wi2.i1.should be
    net.wi2.reg8.should be
    net.wi3.should be
    net.wi3.i1.should be
    net.wi3.reg8.should be
    # Verify that child modules are unique instances
    net.wi1.i1.object_id.should_not == net.wi2.i1.object_id
    net.wi1.reg8.object_id.should_not == net.wi3.reg8.object_id
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("Daisy_3WI")

    net.chain_length.should == 24



  end
end
