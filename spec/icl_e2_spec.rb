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
    network.sub_blocks.size.should == 1
    network.Instrument.is_a?(IJTAG::Instrument).should == true
    network.Instrument.ports.size.should == 2
    network.Instrument.ports[:DO].size.should == 8
    network.Instrument.ports[:DI].size.should == 8
  end 

  it 'captures alias and enumerations from the module def' do
    network = IJTAG.icl_to_model(file: file)
    network.Instrument.aliases.size.should == 6
    network.Instrument.enumerations.size.should == 3
  end

end
