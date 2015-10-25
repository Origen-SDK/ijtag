require "spec_helper"

describe "ICL Example 2 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e2.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates the top level instrument' do
    defn = IJTAG.import(file: file)
    defn.is_a?(IJTAG::NetworkDefinition).should == true
    defn.modules.size.should == 1
    network = defn.instantiate("Instrument")
    network.is_a?(IJTAG::Module).should == true
    network.ports.size.should == 2
    network.ports[:DO].size.should == 8
    network.ports[:DI].size.should == 8
  end 

  it 'captures alias and enumerations from the module def' do
    network = IJTAG.import(file: file).instantiate("Instrument")
    network.aliases.size.should == 6
    network.enumerations.size.should == 3
  end

end
