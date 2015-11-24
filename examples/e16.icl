#include "e4.icl"

Module Broadcast {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source reg1.SO; }

  Instance WI1 Of WrappedInstr {
    InputPort SI = SI;
    InputPort SEL = SEL;
    AllowBroadcastOnScanInterface scan_client; 
  }
  Instance WI2 Of WrappedInstr {
    InputPort SI = inmux2;
    InputPort SEL = SEL;
    AllowBroadcastOnScanInterface scan_client;
  }
  Instance WI3 Of WrappedInstr {
    InputPort SI = inmux3;
    InputPort SEL = SEL;
    AllowBroadcastOnScanInterface scan_client;
  }
  Instance reg1 Of SRegP3 {
    InputPort SI = WI3.SO;
    Parameter Size = 1;
    InputPort DI = 'b0;
  }
  ScanMux inmux2 SelectedBy reg1.DO {
    1'b0 : WI1.SO;
    1'b1 : SI;
  }
  ScanMux inmux3 SelectedBy reg1.DO {
    1'b0 : WI2.SO;
    1'b1 : SI;
  }
}
