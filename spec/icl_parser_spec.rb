require "spec_helper"

describe "The ICL parser" do

  it 'lives' do
    icl = IJTAG::ICL.new(Origen.root.join('examples', 'e1.icl').to_s)
    icl.parse
  end
end
