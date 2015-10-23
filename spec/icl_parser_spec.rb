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
Module Context {     // Some module
  // And another comment
  UseNameSpace ATX;  // Just because
  UseNameSpace Blah;
  ScanOutPort SO { Source reg2.SO; }
}
    END
    p icl
  end

  it "to_ast works for a simple module def" do
    icl = <<-END
// Here is a module    
// That doesn't do much
Module Context {     // Some module
  // And another comment
  UseNameSpace ATX;  // Just because
  /* Some multi
     line comment */
  UseNameSpace Blah;  /* An inline comment */
}
    END
    ast = @parser.parse(icl).to_ast
    ast.should ==
      s(:icl,
        s(:module_def,
          s(:module_name, "Context"),
          s(:useNameSpace_def,
            s(:namespace_name, "ATX")),
          s(:useNameSpace_def,
            s(:namespace_name, "Blah"))))
  end

  it "can parse some real examples" do
    %w(e1).each do |fname|
      p File.read("#{Origen.root}/examples/#{fname}.icl")
    end
  end
end
