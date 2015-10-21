Module Context {
  ScanInPort SI;
  ScanOutPort SO { Source reg2.SO; }
  ShiftEnPort SE;
  CaptureEnPort CE;
  UpdateEnPort UE;
  SelectPort SEL;
  ResetPort RST;
  TCKPort TCK;

  Instance SIB1 Of SIB_mux_pre {
    InputPort SI = SI;
    InputPort fromSO = reg1.SO;
  }
  Instance I1 Of Instrument { InputPort DI = reg1.DO; }
  Instance reg1 Of SReg {
    InputPort SI = SIB1.toSI;
    InputPort DI = I1.DO;
  }
  Instance I2 Of Instrument { InputPort DI = reg2.DO; }
  Instance reg2 Of SReg {
    InputPort SI = SIB1.SO;
    InputPort DI = I2.DO;
  }
}
