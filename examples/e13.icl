#include "e4.icl"

Module Exclusive {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source reg2[0]; }

  Instance WI1 Of WrappedInstr { InputPort SI = SI; }
  Instance WI2 Of WrappedInstr { InputPort SI = SI; }
  Instance WI3 Of WrappedInstr { InputPort SI = SI; }

  ScanMux M4 SelectedBy reg2 {2'b00 : SI;
                              2'b01 : WI1.SO;
                              2'b10 : WI2.SO;
                              2'b11 : WI3.SO;
  }

  ScanRegister reg2[1:0] {ScanInSource M4;
                          CaptureSource 2'b00;
                          ResetValue 2'b00;
  }
}
