require "spec_helper"

describe "ICL Example 4 from the 1687 spec" do

  def file
    "#{Origen.root}/examples/e4.icl"
  end

  it "can be parsed to an ast" do
    icl = File.read(file)
    ast = icl_parser.parse(icl).to_ast
  end

  it 'instantiates the top level module' do
    net = IJTAG.import(file: file).instantiate("WrappedInstr")
    net.i1.module_name.should == "Instrument"
    net.i1.instance_name.should == "I1"
    net.reg8.module_name.should == "SReg"
    net.reg8.instance_name.should == "reg8"
  end

  it 'the model works' do
    net = IJTAG.import(file: file).instantiate("WrappedInstr", Size: 3)
    net.chain_length.should == 8
    
    # Scan in some data
    net.shift!(0b1010_1010, size: 8)
    net.reg8.sr.sr.data.should == 0b1010_1010  # Verify SI hookup

    4.times do
      net.so.data.should == 0
      net.shift!
      net.so.data.should == 1
      net.shift!
    end

    # Update DO
    net.shift!(0b1100_1100, size: 8)
    net.i1.di.data.should == 0
    net.update!
    net.i1.di.data.should == 0b1100_1100

    # Capture and shift out some data
    net.i1.do.drive(0b1001_1001)
    net.capture!
    2.times do
      net.so.data.should == 1
      net.shift!
      net.so.data.should == 0
      net.shift!
      net.so.data.should == 0
      net.shift!
      net.so.data.should == 1
      net.shift!
    end
  end
end
