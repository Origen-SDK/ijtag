#include "e4.icl"

Module Exclusive {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source reg2[0]; }

  Instance WI1 Of WrappedInstr {
    InputPort SI = SI;
    InputPort SEL = SEL1;
  }
  Instance WI2 Of WrappedInstr {
    InputPort SI = SI;
    InputPort SEL = SEL2;
  }
  Instance WI3 Of WrappedInstr {
    InputPort SI = SI;
    InputPort SEL = SEL3;
  }

  // This logic matches the SO selection logic of the mux

  LogicSignal SEL1 {(SEL,reg2[1],reg2[0]) == 3'b101;}
  //LogicSignal SEL2 {(SEL,reg2[1],reg2[0]) == 3'b110;}
  //LogicSignal SEL3 {(SEL,reg2[1],reg2[0]) == 3'b111;}

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
