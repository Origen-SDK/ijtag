#include "e2.icl"
#include "e3.icl"

Module WrappedInstr {
  ScanInPort SI;
  ScanOutPort SO { Source reg8.SO;}
  ShiftEnPort SE;
  CaptureEnPort CE;
  UpdateEnPort UE;
  SelectPort SEL;
  ResetPort RST;
  TCKPort TCK;

  ScanInterface scan_client { Port SI; Port SO; Port SEL; }

  Instance I1 Of Instrument { InputPort DI = reg8.DO; }
  Instance reg8 Of SReg {
    InputPort SI = SI; InputPort DI = I1.DO; Parameter Size = 8;
  }
}
