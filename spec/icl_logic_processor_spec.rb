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
    p = icl_parser.parse(icl).to_ast.find(:logicSignal_def).to_a[1]
    IJTAG::ICL::LogicProcessor.new.evaluate(p, context)
  end

  it "can parse logic expressions" do
    class LB1
      include Origen::Model

      def initialize
        port :SEL, size: 1
        reg :reg2, 0x0, size: 2
      end
    end

    b = LB1.new
    expr = "(SEL,reg2[1],reg2[0]) == 3'b101"
    l(expr, b).should == false
    b.sel.drive(1)
    b.reg2.write(0b01)
    l(expr, b).should == true
  end
end
