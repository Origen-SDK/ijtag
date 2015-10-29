#include "e4.icl"
#include "e6.icl"

Module Multiple_SIB_3WI {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source SIB3.SO; }

  Instance SIB1 Of SIB_mux_pre { InputPort SI = SI;
                                 InputPort fromSO = WI1.SO; }
  Instance SIB2 Of SIB_mux_pre { InputPort SI = SIB1.SO;
                                 InputPort fromSO = WI2.SO; }
  Instance SIB3 Of SIB_mux_pre { InputPort SI = SIB2.SO;
                                 InputPort fromSO = WI3.SO; }
  Instance WI1 Of WrappedInstr { InputPort SI = SIB1.toSI; }
  Instance WI2 Of WrappedInstr { InputPort SI = SIB2.toSI; }
  Instance WI3 Of WrappedInstr { InputPort SI = SIB3.toSI; }
}
