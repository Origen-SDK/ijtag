#include "e4.icl"

Module mux_remote3 {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source mux3; } DataInPort RS[2:0];

  Instance WI1 Of WrappedInstr { InputPort SI = SI; }
  Instance WI2 Of WrappedInstr { InputPort SI = mux1; }
  Instance WI3 Of WrappedInstr { InputPort SI = mux2; }

  ScanMux mux1 SelectedBy RS[2] {
    1'b0 : SI;
    1'b1 : WI1.SO;
  }
  ScanMux mux2 SelectedBy RS[1] {
    1'b0 : mux1;
    1'b1 : WI2.SO;
  }
  ScanMux mux3 SelectedBy RS[0] {
    1'b0 : mux2;
    1'b1 : WI3.SO;
  }
}

Module remote_control {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source reg3.SO; }
  DataOutPort RS[2:0] { Source reg3.DO[2:0]; }

  Instance reg3 Of SRegP3 { InputPort SI = SI; Parameter Size = 3;}
}
