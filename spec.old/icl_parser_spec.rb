require "spec_helper"

describe "The ICL Parser" do
  def parse(string)
    icl_parser.parse(string)
  end

  def p(string)
    parse(string).should be, "parse(\"#{string}\")\n#{icl_parser.last_error_msg.join("\n")}"
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
    ast = icl_parser.parse(icl).to_ast
    ast.should ==
      s(:icl_source,
        s(:module_def,
          s(:SCALAR_ID, "Context"),
          s(:useNameSpace_def,
            s(:SCALAR_ID, "ATX")),
          s(:useNameSpace_def,
            s(:SCALAR_ID, "Blah"))))
  end

  it "can parse some real examples" do
    %w(e1 e2).each do |fname|
      icl = File.read("#{Origen.root}/examples/#{fname}.icl")
      ast = icl_parser.parse(icl).to_ast
    end
  end

  it "hierarchical ports parse correctly" do
    icl = <<-END
Module Context {
  ScanOutPort SO { Source reg2.SO , reg1 , reg3 ; }
}
END
    ast = icl_parser.parse(icl).to_ast
    ast.should ==
      s(:icl_source,
        s(:module_def,
          s(:SCALAR_ID, "Context"),
          s(:scanOutPort_def,
            s(:SCALAR_ID, "SO"),
            s(:source,
              s(:concat_scan_signal,
                s(:scan_signal,
                  s(:hier_port,
                    s(:SCALAR_ID, "reg2"),
                    s(:SCALAR_ID, "SO"))),
                s(:scan_signal,
                  s(:SCALAR_ID, "reg1")),
                s(:scan_signal,
                  s(:SCALAR_ID, "reg3")))))))

  end
end
