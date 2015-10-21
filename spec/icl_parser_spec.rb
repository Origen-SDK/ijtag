require "spec_helper"

describe "The ICL Parser" do

  before :all do
    @parser = IJTAG::ICL::Parser
  end
  
  def parse(string)
    @parser.parse(string)
  end

  def p(string)
    parse(string).should be, "parse(\"#{string}\")\n#{@parser.last_error_msg.join("\n")}"
  end

  def s(type, *children)
    IJTAG::ICL::Node.new(type, children)
  end

  it "can parse namespace defs" do
    p "NameSpace;"
    p "NameSpace ATX;"
    p "NameSpace ATX;\n"
    p "NameSpace ATX; \n"
    p "NameSpace ATX;  "
  end

  it "can parse single line comments" do
    p " // Hello\n"
    p " // Hello   \n"
    p "// Hello\n"
    p "// Hello"
  end

  it "can parse multi line comments" do
    p "/* Hello */"
    p "/* Hello \n How are you today */\n"
  end

  it "can parse a module def" do
    icl = "Module Context { UseNameSpace ATX;\n UseNameSpace Blah;\n }\n"
    p icl
    icl = <<-END
Module Context {
  UseNameSpace ATX;  // Just because
  UseNameSpace Blah;
}
    END
    p icl
  end

  it "to_ast works for a simple module def" do
    icl = <<-END
Module Context {
  UseNameSpace ATX;  // Just because
  UseNameSpace Blah;
}
    END
    ast = @parser.parse(icl).to_ast
    ast.should ==
      s(:icl,
        s(:module,
          s(:name, "Context"),
          s(:use_namespace,
            s(:name, "ATX")),
          s(:use_namespace,
            s(:name, "Blah"))))
  end
end
