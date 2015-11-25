#include "e4.icl"

Module Single_eTAP_3WI {
  ScanInPort eTDI;
  TMSPort eTMS;
  DataInPort SEL;
  TCKPort eTCK;
  ScanOutPort eTDO { Source M2; }

  Instance eTAPC1 Of eTAPC {
    InputPort eTDI = eTDI;
    InputPort eTMS = eTMS;
    InputPort eTCK = eTCK;
    InputPort fromSO = WI3.SO;
  }
  Instance WI1 Of WrappedInstr { InputPort SI = eTAPC1.toSI; }
  Instance WI2 Of WrappedInstr { InputPort SI = WI1.SO; }
  Instance WI3 Of WrappedInstr { InputPort SI = WI2.SO; }
  ScanMux M2 SelectedBy SEL {
    1'b0 : eTDI;
    1'b1 : eTAPC1.eTDO;
  }
}

Module eTAPC {
  ScanInPort eTDI;
  ScanOutPort eTDO { Source IRMux; }
  ScanInPort fromSO;
  ScanOutPort toSI {Source eTDI; }
  TMSPort eTMS;
  TCKPort eTCK;
  ToSelectPort en { Source tdrEn0; }
  ToResetPort tlr { Source FSM.tlr; }
  ToCaptureEnPort CE { Source FSM.CE; }
  ToShiftEnPort SE { Source FSM.CE; }
  ToUpdateEnPort UE { Source FSM.CE; }

  Instance FSM Of TapStates {
    InputPort tms = eTMS;
    InputPort tck = eTCK;
  }
  ScanRegister IR[2:0] {
    ScanInSource eTDI;
    ResetValue 3'b000;
    CaptureSource 3'bx01;
  }
  ScanRegister Bypass {
    ScanInSource eTDI;
    CaptureSource 1'b0;
  }
  ScanMux IRMux SelectedBy FSM.IRSel {
    1'b0 : DRMux;
    1'b1 : IR[0];
  }
  ScanMux DRMux SelectedBy IR[1:0] {
    2'b00 : Bypass;
    2'b01 : fromSO;
  }
  LogicSignal tdrEn0 { IR[1:0] == 2'b01; }
  ScanInterface scan_host {
    Port toSI;
    Port en;
    Port fromSO;
    Port eTCK;
    Port CE;
    Port SE;
    Port UE;
    Port tlr;
  }
}

Module TapStates {
  TMSPort tms;
  TCKPort tck;
  ToResetPort tlr;
  ToIRSelectPort IRSel;
  ToCaptureEnPort CE;
  ToShiftEnPort SE;
  ToUpdateEnPort UE;
}
