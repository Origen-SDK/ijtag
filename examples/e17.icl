#include "e4.icl"

Module Branched_SI {
  ScanInPort SI;
  CaptureEnPort CE;
  ShiftEnPort SE;
  UpdateEnPort UE;
  ResetPort RST;
  TCKPort TCK;

  SelectPort SEL1;
  ScanOutPort SO1 { Source WI2.SO; }

  SelectPort SEL2;
  ScanOutPort SO2 { Source WI3.SO; }

  ScanInterface scan1 { Port SEL1; Port SO1; }
  ScanInterface scan2 { Port SEL2; Port SO2; }

  Instance WI1 Of WrappedInstr { InputPort SI = SI; }
  Instance WI2 Of WrappedInstr { InputPort SI = WI1.SO; }
  Instance WI3 Of WrappedInstr { InputPort SI = SI; }
}
