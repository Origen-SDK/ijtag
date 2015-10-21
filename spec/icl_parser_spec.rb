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
end
