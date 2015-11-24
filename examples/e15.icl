#include "e4.icl"

Module Exclusive_broadcast {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source reg3[0]; }

  Instance WI1 Of WrappedInstr {
    InputPort SI = SI;
    InputPort SEL = SEL1;
    AllowBroadcastOnScanInterface scan_client;
  }
  Instance WI2 Of WrappedInstr {
    InputPort SI = SI;
    InputPort SEL = SEL2;
    AllowBroadcastOnScanInterface scan_client;
  }
  Instance WI3 Of WrappedInstr {
    InputPort SI = SI;
    InputPort SEL = SEL3;
    AllowBroadcastOnScanInterface scan_client;
  }

  // Select if in broadcast mode or the SO of this instance is selected
  LogicSignal SEL1 {SEL & (reg3[2] | (~reg3[1] & reg3[0]));}
  LogicSignal SEL2 {SEL & (reg3[2] | (reg3[1] & ~reg3[0]));}
  LogicSignal SEL3 {SEL & (reg3[2] | (reg3[1] & reg3[0]));}

  ScanMux M4 SelectedBy reg3[1:0] {
    2'b00 : SI;
    2'b01 : WI1.SO;
    2'b10 : WI2.SO;
    2'b11 : WI3.SO;
  }
  ScanRegister reg3[2:0] {
    ScanInSource M4;
    CaptureSource 3'b00;
    ResetValue 3'b00;
  }
}
