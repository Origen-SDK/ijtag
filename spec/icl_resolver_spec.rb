require "spec_helper"

describe "The ICL AST Resolver" do

  def r
    @r ||= IJTAG::ICL::Resolver.new
  end

  it "can resolve addition expressions" do
     ast = s(:add,
             s(:add,
               s(:POS_INT, 2),
               s(:POS_INT, 5)),
             s(:POS_INT, 3))

     r.process(ast).should == s(:POS_INT, 10)             
  end

  it "can deal with binary and hex numbers in expressions" do
     ast = s(:add,
             s(:add,
               s(:UNSIZED_BIN_NUMBER, "10"),
               s(:UNSIZED_HEX_NUMBER, "10")),
             s(:POS_INT, 3))

     r.process(ast).should == s(:POS_INT, 21)             
  end

  it "also handles sized numbers in expressions" do
     ast = s(:add,
             s(:add,
               s(:sized_bin_number,
                 s(:size, 16),
                 s(:UNSIZED_BIN_NUMBER, "10")),
               s(:sized_hex_number,
                 s(:size, 16),
                 s(:UNSIZED_HEX_NUMBER, "10"))),
             s(:sized_dec_number,
               s(:size, 16),
               s(:POS_INT, 3)))

     r.process(ast).should == s(:POS_INT, 21)             
  end

  it "can resolve parameters" do
  end
end
