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

     r.process(ast).should == s(:POS_INT, 8)             
  end
end
