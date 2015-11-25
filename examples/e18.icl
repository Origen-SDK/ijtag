#include "e4.icl"

Module Branched_then_merged {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source reg1.SO; }

  Instance WI1 Of WrappedInstr { InputPort SI = SI; }
  Instance WI2 Of WrappedInstr { InputPort SI = WI1.SO; }
  Instance WI3 Of WrappedInstr { InputPort SI = SI; }

  Instance reg1 Of SReg {
    InputPort SI = mux;
    Parameter Size = 1;
    InputPort DI = 'b0;
  }
  ScanMux mux SelectedBy reg1.DO {
    1'b0 : WI2.SO;
    1'b1 : WI3.SO;
  }
}
