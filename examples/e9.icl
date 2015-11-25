#include "e4.icl"

Module mux_inline3 {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source reg3.SO; }

  Instance WI1 Of WrappedInstr { InputPort SI = SI; }
  Instance WI2 Of WrappedInstr { InputPort SI = mux1; }
  Instance WI3 Of WrappedInstr { InputPort SI = mux2; }

  Instance reg3 Of SReg { InputPort SI = mux3; Parameter Size = 3;
                          InputPort DI = 'b0; }

  ScanMux mux1 SelectedBy reg3.DO[2] {
    1'b0 : SI;
    1'b1 : WI1.SO;
  }
  ScanMux mux2 SelectedBy reg3.DO[1] {
    1'b0 : mux1;
    1'b1 : WI2.SO;
  }
  ScanMux mux3 SelectedBy reg3.DO[0] {
    1'b0 : mux2;
    1'b1 : WI3.SO;
  }
}
