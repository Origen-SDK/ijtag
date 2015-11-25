#include "e4.icl"

Module WSP1500_SWIR {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source IR_MUX; }

  ScanRegister SWIR {ScanInSource SI; ResetValue 1'b1;}
  ScanRegister WBY {ScanInSource SWIR; ResetValue 1'b1;}

  Instance WIR Of SReg { InputPort SI = SWIR; Parameter Size = 2;}
  Instance WI1 Of WrappedInstr { InputPort SI = SWIR; }
  Instance WI2 Of WrappedInstr { InputPort SI = SWIR; }
  Instance WI3 Of WrappedInstr { InputPort SI = SWIR; }

  ScanMux DR_MUX SelectedBy WIR[1:0] {2'b00 : WBY;
  2'b01 : WI1.SO;
  2'b10 : WI2.SO;
  2'b11 : WI3.SO;
  }

  ScanMux IR_MUX SelectedBy SWIR {1'b0 : DR_MUX;
  1'b1 : WIR[0];
  }
}
