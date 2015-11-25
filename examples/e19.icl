#include "e4.icl"

Module WSP1500 {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source IR_MUX; }
  DataInPort SWIR;

  ScanRegister WIR[1:0] {
    ScanInSource SI;
    ResetValue 2'b0;
    CaptureSource 2'b01;
  }
  ScanRegister WBY {
    ScanInSource SI;
    CaptureSource 1'b0;
  }

  Instance WI1 Of WrappedInstr { InputPort SI = SI; }
  Instance WI2 Of WrappedInstr { InputPort SI = SI; }
  Instance WI3 Of WrappedInstr { InputPort SI = SI; }

  ScanMux DR_MUX SelectedBy WIR[1:0] {
    2'b00 : WBY;
    2'b01 : WI1.SO;
    2'b10 : WI2.SO;
    2'b11 : WI3.SO;
  }
  ScanMux IR_MUX SelectedBy SWIR {
    1'b0 : DR_MUX;
    1'b1 : WIR[0];
  }
}
