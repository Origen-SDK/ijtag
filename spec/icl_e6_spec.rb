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
    net.sr.should be
    net.SIBmux.should be
  end

  it 'the scan chain can be traversed' do
    net = IJTAG.import(file: file).instantiate("SIB_mux_pre", Size: 3)
    net.si.ports.should == [net.sibmux.input0, net.tosi]
    net.sibmux.output.ports.should == [net.sr.si]
    net.sr.so.ports.should == [net.so]
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("SIB_mux_pre")
    a = net.si
    b = net.fromSO
    a.drive(1)
    b.drive(0)
    net.shift!
    net.so.data.should == 1
    net.shift!
    net.so.data.should == 1
    net.shift!
    net.so.data.should == 1
    net.update!
    net.so.data.should == 1
    net.shift!
    net.so.data.should == 0
    net.shift!
    net.so.data.should == 0
    net.shift!
    net.so.data.should == 0
    net.update!
    net.so.data.should == 0
    net.shift!
    net.so.data.should == 1
  end
end
