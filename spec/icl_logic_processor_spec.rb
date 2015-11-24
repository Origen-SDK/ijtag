require "spec_helper"

describe "The ICL Logic Expression processor" do

  # Takes a logic expression string and evaluates it in the context of the
  # given object
  def l(val, context)
    icl = <<END
Module Temp {
  LogicSignal SIG {#{val};}
}
END
    ast = icl_parser.parse(icl).to_ast
    l_ast = ast.find(:logicSignal_def).to_a[1]
    IJTAG::ICL::LogicProcessor.new.evaluate(l_ast, context)
  end

  it "can parse logic expressions" do
    class LB1
      include Origen::Model

      def initialize
        port :SEL, size: 1
        reg :reg2, 0x0, size: 2
        reg :reg3, 0x0, size: 3
      end
    end

    b = LB1.new
    expr = "(SEL,reg2[1],reg2[0]) == 3'b101"
    l(expr, b).should == 0
    b.sel.drive(1)
    b.reg2.write(0b01)
    l(expr, b).should == 1

    b = LB1.new
    expr = "SEL & (reg3[2] | (~reg3[1] & reg3[0]))"
    b.sel.drive(0)
    l(expr, b).should == 0
    b.sel.drive(1)
    l(expr, b).should == 0
    b.reg3.write(0b100)
    l(expr, b).should == 1
    b.reg3.write(0b101)
    l(expr, b).should == 1
    b.reg3.write(0b001)
    l(expr, b).should == 1
    b.reg3.write(0b010)
    l(expr, b).should == 0
  end
end
