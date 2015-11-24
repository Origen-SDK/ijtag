require "spec_helper"

describe "The ICL Expression processor" do

  class Resolver < IJTAG::ICL::Processor
    include IJTAG::ICL::ExpressionProcessor
  end

  def r
    @r ||= Resolver.new
  end


  it "can resolve addition expressions" do
     ast = s(:add,
             s(:add,
               s(:POS_INT, 2),
               s(:POS_INT, 5)),
             s(:POS_INT, 3))

     r.process(ast).should == 10
  end

  it "can deal with binary and hex numbers in expressions" do
     ast = s(:add,
             s(:add,
               s(:UNSIZED_BIN_NUMBER, "10"),
               s(:UNSIZED_HEX_NUMBER, "10")),
             s(:POS_INT, 3))

     r.process(ast).should == 21
  end

  it "also handles sized numbers in expressions" do
     ast = s(:add,
             s(:add,
               s(:sized_bin_number,
                 s(:POS_INT, 16),
                 s(:UNSIZED_BIN_NUMBER, "10")),
               s(:sized_hex_number,
                 s(:POS_INT, 16),
                 s(:UNSIZED_HEX_NUMBER, "10"))),
             s(:sized_dec_number,
               s(:POS_INT, 16),
               s(:POS_INT, 3)))

     r.process(ast).should == 21
  end

  it "can resolve subtractions" do
     ast = s(:subtract,
             s(:subtract,
               s(:POS_INT, 15),
               s(:POS_INT, 5)),
             s(:POS_INT, 3))

     r.process(ast).should == 7
  end

  it "can resolve multiplications" do
     ast = s(:multiply,
             s(:multiply,
               s(:POS_INT, 15),
               s(:POS_INT, 5)),
             s(:POS_INT, 3))

     r.process(ast).should == 225
  end

  it "can resolve divisions" do
     ast = s(:divide,
             s(:divide,
               s(:POS_INT, 45),
               s(:POS_INT, 5)),
             s(:POS_INT, 3))

     r.process(ast).should == 3
  end

  it "can resolve mods" do
     ast = s(:modulus,
             s(:modulus,
               s(:POS_INT, 49),
               s(:POS_INT, 5)),
             s(:POS_INT, 3))

     r.process(ast).should == 1
  end
end
