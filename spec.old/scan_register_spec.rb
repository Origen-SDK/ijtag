require "spec_helper"

describe "A ScanRegister statement" do

#  it 'The scanRegister_name shall shift from left to right, meaning that the bit associated with the index
#      to the left of the “:” in the index range shifts toward the index to the right of the “:”'

  it 'The scanRegister_scanInSource shall be included in the scanRegister_item list.' do
    valid_icl = <<-END
Module SReg {    
  ScanInPort      SI;
  ScanRegister SR[7:0] { ScanInSource SI; }
}
    END

    invalid_icl = <<-END
Module SReg {    
  ScanInPort      SI;
  ScanRegister SR[7:0] {  }
}
    END

    -> { IJTAG.import(valid_icl).instantiate(:SReg) }.should_not raise_error
    -> { IJTAG.import(invalid_icl).instantiate(:SReg) }.should raise_error(/must declare a ScanInSource/)
  end

#  it 'The scanRegister_scanInSource referring to a multi-bit scanRegister_name shall always specify
#      the right most bit, meaning the bit referenced by the index to the right of the “:” in the range.'

  it 'Except for the attribute_def, there shall be at most one occurrence of each element type in a
      scanRegister_item.' do
    valid_icl = <<-END
Module SReg {    
  ScanInPort      SI;
  DataInPort      DI[7:0];
  ScanRegister SR[7:0] { ScanInSource SI;
                         CaptureSource DI;
                         ResetValue 8'b00000000; }                   
}
    END

    invalid_icl = <<-END
Module SReg {    
  ScanInPort      SI;
  DataInPort      DI[7:0];
  ScanRegister SR[7:0] { ScanInSource SI;
                         CaptureSource DI;
                         ResetValue 8'b00000000;
                         CaptureSource DI;
  }                   
}
    END
    -> { IJTAG.import(valid_icl).instantiate(:SReg) }.should_not raise_error
    -> { IJTAG.import(invalid_icl).instantiate(:SReg) }.should raise_error(/only one CaptureSource/)
  end

#  it 'If used, the width of scanRegister_DefaultLoadValue, scanRegister_CaptureSource, and
#      scanRegister_ResetValue shall match the width of the scanRegister_name.'
#
#  it 'The width of enum_value referenced by scanRegister_refEnum shall match the width of
#      scanRegister_name.'
#
#  it 'The enum_symbol optionally used in the scanRegister_defaultLoadValue, scanRegister_captureSource,
#      or scanRegister_resetValue statement shall exist in the referenced scanRegister_refEnum.'
#
#  it 'A scanRegister_name that reacts to reset shall include the corresponding scanRegister_resetValue
#      specification.'
#
#  it 'A module_def having at least one ScanRegister with a specified ResetValue shall have at most a
#      single reset_signal so that the source of the reset signal for the ScanRegister is unambiguous.'
#
#  it 'For read data to be predictable at the scan register, the scanRegister_CaptureSource element shall
#      be specified as the source of the captured data.'
#
#  it 'A ScanRegister that is part of the active scan chain or is shadowing parts of the active scan chain
#      shall hold its data when ShiftEn is low between the CaptureEn and the UpdateEn cycle.'
#
#  it 'The data that enters on the ScanInSource shall exit unaltered (excepting possible inversion) n TCK
#      shift cycles later, where n is the width of the scanRegister_name and a shift cycle is a TCK pulse
#      with ShiftEn active.'
#
#  it 'The first time a ScanRegister is on the active scan chain, any bit that is not a care bit to satisfy the
#      requirements of the current iApply shall be loaded with the scanRegister_defaultLoadValue if it is
#      specified, else the scanRegister_resetValue if it is specified and not X, and if neither is specified,
#      it shall be loaded with 0.'
#
#  it 'The first time a ScanRegister is on the active scan chain after it has been reset, any bit with a non-
#      X reset value that is not a care bit to satisfy the requirements of the current iApply shall be loaded
#      with the specified scanRegister_resetValue. Any bit with an X reset value shall be loaded as
#      expressed in rule m).'
#
#  it 'When the ScanRegister is on the active scan chain, any bit that is not a care bit to satisfy the
#      requirements of the current iApply (including the iApplyEndState, if present, and the values of
#      any downstream DataRegister bits and DataInPort bits that must be justified) shall be loaded with
#      the same value as the previous time it was on the active scan chain.'
#
#  it 'Any bit of a ScanRegister fanning out to the select of ScanMux or to a SelectPort or ToSelectPort
#      of a ScanInterface anywhere in the hierarchy shall have a 0 or 1 value specified in the
#      scanRegister_ResetValue.'
#
#  it 'The update stage of the ScanRegister shall assume the specified scanRegister_resetValue when its
#      associated reset_signal is activated.'
#
#  it 'Any bit of a ScanRegister driving a data_signal anywhere in the hierarchy shall have an update
#      stage (or a mechanism to cause equivalent behavior) that only changes when the ScanRegister is
#      active and its associated updateEn_signal is high.'
#
#  it 'When both scanRegister_defaultLoadValue and scanRegister_resetValue exist, the values in the
#      bits of scanRegister_defaultLoadValue shall match the non-X values in the corresponding bits of
#      scanRegister_resetValue.'
#
#  it 'If scanRegister_CaptureSource references a name that is both present as a reg_port_signal_id as
#      well as an Enum of the supplied RefEnum, then precedence shall go to the Enum.'
#
#  it 'A scanRegister_scanInSource referring to a multi-bit scanRegister_name may specify only the
#      SCALAR_ID portion of the name; the rightmost bit as defined in rule c) shall be the source.'

end
