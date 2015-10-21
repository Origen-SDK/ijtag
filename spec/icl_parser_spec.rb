require 'spec_helper'

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

  it "can parse namespace defs" do
    p 'NameSpace;'
    p 'NameSpace ATX;'
    p 'NameSpace ATX;\n'
    p 'NameSpace ATX; \n'
    p 'NameSpace ATX;  '
  end

  it "can parse single line comments" do
    p ' // Hello\n'
    p ' // Hello   \n'
    p '// Hello\n'
    p '// Hello'
  end

  it "can parse multi line comments" do
    p '/* Hello */'
    p '/* Hello \n How are you today */\n'
  end

  #it "can parse a module def" do
  #  p 'Module Context { UseNameSpace ATX;\n UseNameSpace Blah;\n }\n'
  #end
end
