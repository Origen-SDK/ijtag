Module SIB_mux_pre {
  ScanInPort    SI;
  CaptureEnPort CE;
  ShiftEnPort   SE;
  UpdateEnPort  UE;
  SelectPort    SEL;
  ResetPort     RST;
  TCKPort       TCK;
  ScanOutPort   SO { Source SR; }
  ScanInterface client {
    Port SI; Port CE; Port SE; Port UE;
    Port SEL; Port RST; Port TCK; Port SO;
  }
  ScanInPort      fromSO;
  ToCaptureEnPort toCE;
  ToShiftEnPort   toSE;
  ToUpdateEnPort  toUE;
  ToSelectPort    toSEL;
  ToResetPort     toRST;
  ToTCKPort       toTCK;
  ScanOutPort     toSI { Source SI; }
  ScanInterface host {
    Port fromSO; Port toCE; Port toSE; Port toUE;
    Port toSEL; Port toRST; Port toTCK; Port toSI;
  }
  ScanRegister SR {
    ScanInSource SIBmux; CaptureSource SR; ResetValue 1'b0;
  }
  ScanMux SIBmux SelectedBy SR {
    1'b0 : SI;
    1'b1 : fromSO;
  }
}
