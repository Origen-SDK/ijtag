Module Context {
  ScanInPort    SI;
  ScanOutPort   SO { Source  reg2;} // implicitly bit 0
  ShiftEnPort   SE;
  CaptureEnPort CE;
  UpdateEnPort  UE;
  SelectPort    SEL;
  ResetPort     RST;
  TCKPort       TCK;

  Instance SIB1 Of SIBmuxpre {
    InputPort SI = SI;
    InputPort fromSO = reg1.SO;
  }
  Instance I1 Of Instrument { InputPort DI = reg1.DO; }
  Instance reg1 Of SReg1 {
    InputPort SI = SIB1.toSI;
    InputPort DI = I1.DO;
  }
  Instance I2 Of Instrument { InputPort DI = reg2.DO; }
  Instance reg2 Of SReg1 {
    InputPort SI = SIB1.SO;
    InputPort DI = I2.DO;
  }
}

Module Instrument {
  DataInPort  DI[7:0];
  DataOutPort DO[7:0];
}

Module Instrument {
  DataInPort  DI[7:0];
  DataOutPort DO[7:0];
  Alias enable = DI[7] { RefEnum YesNo; }
  Alias mode[3:0] = DI[6:5],DI[3:2] { RefEnum Modes; }
  Alias data[2:0] = DI[4],DI[1:0];
  Alias okay = DO[0]{ RefEnum PassFail; }
  Alias done = DO[1] { RefEnum YesNo; }
  Alias count[5:0] = DO[7:2];
 
  Enum PassFail { Pass = 1'b1;
                  Fail = 1'b0; }
  Enum YesNo    { Yes  = 1'b1;
                  No   = 1'b0; }
  Enum Modes    { red   = 4'b0011;
                  blue  = 4'b1000;
                  green = 4'b0100; }
}

Module SReg {
  ScanInPort    SI;
  ScanOutPort   SO { Source  SR[0];}          
  ShiftEnPort   SE;
  CaptureEnPort CE;
  UpdateEnPort  UE;
  SelectPort    SEL;
  ResetPort     RST;
  TCKPort       TCK;
  DataInPort    DI[7:0];
  DataOutPort   DO[7:0] {Source SR; }
  ScanInterface scan_client { Port SI; Port SO; Port SEL; }

  ScanRegister SR[7:0] { ScanInSource SI;    
                         CaptureSource DI; 
                         ResetValue 8'b00000000; }
}

Module SReg {
  Parameter MSB = 7;
  ScanInPort    SI;
  ScanOutPort   SO { Source  SR[0];}          
  ShiftEnPort   SE;
  CaptureEnPort CE;
  UpdateEnPort  UE;
  SelectPort    SEL;
  ResetPort     RST;
  TCKPort       TCK;
  DataInPort    DI[$MSB:0];
  DataOutPort   DO[$MSB:0] {Source SR; }
  ScanInterface scan_client { Port SI; Port SO; Port SEL; }

  ScanRegister SR[$MSB:0] { ScanInSource SI;    
                         CaptureSource DI; 
                         ResetValue $MSB'b0; }
}

Module SReg {
  Parameter Size = 8;
  ScanInPort    SI;
  ScanOutPort   SO { Source  SR[0];}          
  ShiftEnPort   SE;
  CaptureEnPort CE;
  UpdateEnPort  UE;
  SelectPort    SEL;
  ResetPort     RST;
  TCKPort       TCK;
  DataInPort    DI[$Size-1:0];
  DataOutPort   DO[$Size-1:0] {Source SR; }
  ScanInterface scan_client { Port SI; Port SO; Port SEL; }

  ScanRegister SR[$Size-1:0] { ScanInSource SI;    
                               CaptureSource DI; 
                               ResetValue $Size'b0; }
}

Module WrappedInstr {
  ScanInPort    SI;
  ScanOutPort   SO { Source reg1.SO;}          
  ShiftEnPort   SE;
  CaptureEnPort CE;
  UpdateEnPort  UE;
  SelectPort    SEL;
  ResetPort     RST;
  TCKPort       TCK;
  ScanInterface scan_client { Port SI; Port SO; Port SEL; }

  Instance I1 Of Instrument { InputPort DI = reg1.DO; }
  Instance reg8 Of SReg { 
    InputPort SI = SI; InputPort DI = I1.DO; Parameter Size = 8;
  }
} 

Module Daisy_3WI {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source WI3.SO; }
  Instance WI1 Of WrappedInstr { InputPort SI = SI; }
  Instance WI2 Of WrappedInstr { InputPort SI = WI1.SO; }
  Instance WI3 Of WrappedInstr { InputPort SI = WI2.SO; }
}

Module SIB_mux_pre {
  ScanInPort     SI;      
  CaptureEnPort  CE;
  ShiftEnPort    SE;
  UpdateEnPort   UE;
  SelectPort     SEL;
  ResetPort      RST;
  TCKPort        TCK;
  ScanOutPort    SO { Source SR; LaunchEdge Rising; } 
  ScanInterface client {
    Port SI; Port CE; Port SE; Port UE;
    Port SEL; Port RST; Port TCK; Port SO; 
  }
  ScanInPort       fromSO;
  ToCaptureEnPort  toCE;
  ToShiftEnPort    toSE;
  ToUpdateEnPort   toUE;
  ToSelectPort     toSEL;
  ToResetPort      toRST;
  ToTCKPort        toTCK;
  ScanOutPort      toSI { Source SI; LaunchEdge Rising; } 
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

Module Single_SIB_3WI {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source SIB1.SO; }

  Instance SIB1 Of SIB_mux_pre { InputPort SI = SI;
                                 InputPort fromSO = WI3.SO; }
  Instance WI1 Of WrappedInstr { InputPort SI = SIB1.toSI; }
  Instance WI2 Of WrappedInstr { InputPort SI = WI1.SO; }
  Instance WI3 Of WrappedInstr { InputPort SI = WI2.SO; }
}

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

Module mux3_inline {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source reg3.SO; }

  Instance WI1 Of WrappedInstr { InputPort SI = SI; }
  Instance WI2 Of WrappedInstr { InputPort SI = mux1; }
  Instance WI3 Of WrappedInstr { InputPort SI = mux2; }
  Instance reg3 Of SReg { InputPort SI = mux3; Parameter Size = 3;}
  ScanMux mux1 SelectedBy reg3[2] {
    1'b0 : SI;
    1'b1 : WI1.SO;
  }
  ScanMux mux2 SelectedBy reg3[1] {
    1'b0 : mux1;
    1'b1 : WI2.SO;
  }
  ScanMux mux3 SelectedBy reg3[0] {
    1'b0 : mux2;
    1'b1 : WI3.SO;
  }
}

Module mux3_remote {
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
  TCKPort TCK; ScanOutPort SO { Source reg3; }
  DataOutPort RS[2:0] { Source reg3[2:0]; }
  
  Instance reg3 Of SReg { InputPort SI = mux3; Parameter Size = 3;}
}

Module Nested_SIB_3WI {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source SIB3.SO; }

  Instance SIB1 Of SIB_mux_pre { InputPort SI = SI;
                                 InputPort fromSO = SIB2.SO; }
  Instance SIB2 Of SIB_mux_pre { InputPort SI = WI1.SO;
                                 InputPort fromSO = SIB3.SO; }
  Instance SIB3 Of SIB_mux_pre { InputPort SI = WI2.SO;
                                 InputPort fromSO = WI3.SO; }
  Instance WI1 Of WrappedInstr { InputPort SI = SIB1.toSI; }
  Instance WI2 Of WrappedInstr { InputPort SI = SIB2.toSI; }
  Instance WI3 Of WrappedInstr { InputPort SI = SIB3.toSI; }
}

Module BAD_Nested_SIB_3WI {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source SIB3.SO; }

  Instance SIB1 Of SIB_mux_post { InputPort SI = SI;
                                  InputPort fromSO = SIB2.SO; }
  Instance SIB2 Of SIB_mux_post { InputPort SI = WI1.SO;
                                  InputPort fromSO = SIB3.SO; }
  Instance SIB3 Of SIB_mux_post { InputPort SI = WI2.SO;
                                  InputPort fromSO = WI3.SO; }
  Instance WI1 Of WrappedInstr { InputPort SI = SIB1.toSI; }
  Instance WI2 Of WrappedInstr { InputPort SI = SIB2.toSI; }
  Instance WI3 Of WrappedInstr { InputPort SI = SIB3.toSI; }
}

Module Exclusive {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source reg2[0]; }
 
  Instance WI1 Of WrappedInstr { InputPort SI = SI; }
  Instance WI2 Of WrappedInstr { InputPort SI = SI; }
  Instance WI3 Of WrappedInstr { InputPort SI = SI; }

  ScanMux M4 SelectedBy reg2.DO[1:0] {2'b00 : SI;
                                   2'b01 : WI1.SO; 
                                   2'b10 : WI2.SO; 
                                   2'b11 : WI3.SO;
  }
  ScanRegister reg2[1:0] {ScanInSource M4;
                          CaptureSource 2'b00;
                          ResetValue 2'b00;
  }
}

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
  LogicSignal SEL1 {SEL,reg2[1],reg2[0] == 3'b101;}
  LogicSignal SEL2 {SEL,reg2[1],reg2[0] == 3'b110;}
  LogicSignal SEL3 {SEL,reg2[1],reg2[0] == 3'b111;}
  ScanMux M4 SelectedBy reg2.DO[1:0] {2'b00 : SI;
                                      2'b01 : WI1.SO; 
                                      2'b10 : WI2.SO; 
                                      2'b11 : WI3.SO;
  }
  ScanRegister reg2[1:0] {ScanInSource M4;
                          CaptureSource 2'b00;
                          ResetValue 2'b00;
  }
}

Module Exclusive_broadcast {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source reg2[0]; }
 
  Instance WI1 Of WrappedInstr { InputPort SI = SI;
                  InputPort SEL = SEL1;
                  AllowBroadcastOnScanInterface scan_client;
  }
  Instance WI2 Of WrappedInstr { InputPort SI = SI;
                  InputPort SEL = SEL2;
                  AllowBroadcastOnScanInterface scan_client;
  }
  Instance WI3 Of WrappedInstr { InputPort SI = SI;
                  InputPort SEL = SEL3;
                  AllowBroadcastOnScanInterface scan_client;
  }
  // Select if in broadcast mode or if this instance's SO is selected
  LogicSignal SEL1 {SEL & (reg2[2] | (~reg2[1] & reg2[0]));}
  LogicSignal SEL2 {SEL & (reg2[2] | (reg2[1] & ~reg2[0]));}
  LogicSignal SEL3 {SEL & (reg2[2] | (reg2[1] & reg2[0]));}
  ScanMux M4 SelectedBy reg2.DO[1:0] {2'b00 : SI;
                                      2'b01 : WI1.SO; 
                                      2'b10 : WI2.SO; 
                                      2'b11 : WI3.SO;
  }
  ScanRegister reg2[1:0] {ScanInSource M4;
                          CaptureSource 2'b00;
                          ResetValue 2'b00;
  }
}

Module Broadcast {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source reg1.SO; }

  Instance WI1 Of WrappedInstr { InputPort SI = SI;
                  InputPort SEL = SEL;
                  AllowBroadcastOnScanInterface scan_client; }
  Instance WI2 Of WrappedInstr { InputPort SI = inmux2;
               InputPort SEL = SEL;
               AllowBroadcastOnScanInterface scan_client; }
  Instance WI3 Of WrappedInstr { InputPort SI = inmux3;
               InputPort SEL = SEL;
               AllowBroadcastOnScanInterface scan_client; }
  Instance reg1 Of SReg { InputPort SI = WI3.SO; Parameter Size = 1;}
  ScanMux inmux2 SelectedBy reg1.DO {
    1'b0 : WI1.SO;
    1'b1 : SI;
  }
  ScanMux inmux3 SelectedBy reg1.DO {
    1'b0 : WI2.SO;
    1'b1 : SI;
  }
}

Module Branched_SI {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO1 { Source WI2.SO; }
  ScanOutPort SO2 { Source WI3.SO; }
  ScanInterface scan1 { Port SEL1; Port SO1; }
  ScanInterface scan2 { Port SEL2; Port SO2; }

  Instance WI1 Of WrappedInstr { InputPort SI = SI; }
  Instance WI2 Of WrappedInstr { InputPort SI = WI1.SO; }
  Instance WI3 Of WrappedInstr { InputPort SI = SI; }
}

Module Branched_then_merged {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source reg1.SO; }

  Instance WI1 Of WrappedInstr { InputPort SI = SI; }
  Instance WI2 Of WrappedInstr { InputPort SI = WI1.SO; }
  Instance WI3 Of WrappedInstr { InputPort SI = SI; }

  Instance reg1 Of SReg { InputPort SI = mux; Parameter Size = 1;}
  ScanMux mux SelectedBy reg1 {
    1'b0 : WI2.SO;
    1'b1 : WI3.SO;
  }
}

Module WSP1500_SWIR {
  ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
  UpdateEnPort UE; SelectPort SEL; ResetPort RST;
  TCKPort TCK; ScanOutPort SO { Source M2; }

  ScanRegister SWIR {ScanInSource SI; ResetValue 1'b1;}
  ScanRegister WBY {ScanInSource SWIR.SO; ResetValue 1'b1;}
  Instance WIR Of SReg { InputPort SI = SWIR.SO; Parameter Size = 2;}

  Instance WI1 Of WrappedInstr { InputPort SI = SWIR.SO; }
  Instance WI2 Of WrappedInstr { InputPort SI = SWIR.SO; }
  Instance WI3 Of WrappedInstr { InputPort SI = SWIR.SO; }

  ScanMux M4 SelectedBy WIR.DO[1:0] {2'b00 : WBY;
                                     2'b01 : WI1.SO; 
                                     2'b10 : WI2.SO; 
                                     2'b11 : WI3.SO;
  }
  ScanMux M2 SelectedBy SWIR {1'b0 : M4;
                              1'b1 : WIR.SO; 

  }
}

Module Single_eTAP_3WI {
  ScanInPort eTDI; TMSPort eTMS;
  TCKPort TCK; ScanOutPort eTDO { Source M2; }

  Instance eTAPC1 Of eTAPC { InputPort eTDI = eTDI;
                             InputPort eTMS = eTMS;
                             InputPort eTCK = eTCK;
                             InputPort SEL = SEL;
                             InputPort fromSO = WI3.SO; }
  Instance WI1 Of WrappedInstr { InputPort SI = eTAPC1.toSI; }
  Instance WI2 Of WrappedInstr { InputPort SI = WI1.SO; }
  Instance WI3 Of WrappedInstr { InputPort SI = WI2.SO; }
  ScanMux M2 SelectedBy SEL {1'b0 : eTAPC.eTDO;
                             1'b1 : eTDI; 
  }
}

Module eTAPC {
  ScanInPort   eTDI;
  ScanOutPort  eTDO { Source IRSelMux; }
  ScanInPort fromSO;
  ScanOutPort toSI {Source eTDI; }
  TMSPort      eTMS;
  TCKPort      eTCK;
  ToSelectPort en  { Source tdrEn0; }
  ToResetPort  tlr { Source FSM.tlr; }
  Instance FSM Of TapStates { 
    InputPort tms = eTMS;
    InputPort tck = eTCK;    }
  ToCaptureEnPort CE { Source FSM.CE; }
  ToShiftEnPort SE { Source FSM.CE; }
  ToUpdateEnPort UE { Source FSM.CE; }
  ScanRegister IR[2:0] { ResetValue 3'b000;
                         CaptureSource 3'bx01; }
  ScanRegister Bypass  { CaptureSource 1'b0;   }
  ScanMux IRMux SelectedBy FSM.IRSel { 1'b0 : DRMux;
                                       1'b1 : IR[0]; }
  ScanMux DRMux SelectedBy IR[1:0] { 2'b00 : Bypass;
                                     2'b01 : fromSO;    }
  LogicSignal tdrEn0 { IR[1:0] == 2'b01;  }
  ScanInterface scan_host { Port toSI; Port en; Port fromSO; Port eTCK;
                            Port CE; Port SE; Port UE; Port tlr; }
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
 
Module MyInstrument {
  DataInPort  In[3:0];
  DataOutPort Out[3:0];
}

Module MBIST_engine {
  DataInPort Cntl[3:0];
  DataInPort Go;
  DataOutPort Status[1:0];
  DataOutPort State[3:0];
}

Module MBIST_engine {
  DataInPort Cntl[3:0];
  DataInPort Go;
  DataOutPort Status[1:0];
  DataOutPort State[3:0];
}

Module Memory {
  DataOutPort fail_location[7:0];
  DataOutPort fall_data[15:0];
}
 
Module MBIST_engine {
  DataInPort Cntl[3:0];
  DataInPort Go;
  DataOutPort Status[1:0];
  DataOutPort State[3:0];
}

Module Memory {
  DataOutPort fail_location[7:0];
  DataOutPort fail_data[15:0];
}

Module BISTed_Memory {
  DataInPort Cntl[3:0];
  DataInPort Go;
  DataOutPort Status[1:0] {
    Source BIST1.Status; } 
  DataOutPort State[3:0] {
    Source BIST1.State; }
  DataOutPort fail_location[7:0] {
    Source Mem1.fail_location; } 
  DataOutPort fail_data[15:0] {
    Source Mem1.fail_data; } 
  Instance BIST1 Of MBIST_engine {
    InputPort Cntl = Cntl;
    InputPort Go = Go;
  }
  Instance Mem1 Of Memory;
}

Module InstA {
  DataInPort DH[7:0];
  DataInPort DL[7:0];
  DataOutPort QH[7:0] { Source Q[15:8] ; }
  DataOutPort QL[7:0] { Source Q[7:0] ; } 
  AddressPort AH[19:16];
  AddressPort AL[15:0];
  ReadEnPort RE; //One and only one RE/WE ports on
  WriteEnPort WE; //modules containing addressable regs
  OneHotDataGroup Q[15:0] {
    DataRegister R0[15:0] {
      AddressValue 8'd0;
    }
    DataRegister R1[15:0] {
      AddressValue 8'd1;
    }
    DataRegister R72[15:0] {
      AddressValue 8'd72;
    }
  }
  Alias Ena = R0[15];
  Alias AMode[8:0] = R0[14:6] {
    RefEnum Amodes;
  }
  Alias RH = R72[0];
  Enum AModes { M1 = 9'h0; M9 = 9'h0A4; }
}
Module BlockA {
  DataInPort D[15:0];
  DataOutPort Q[15:0] { Source QM[15:0]; }
  AddressPort A[19:0];
  ReadEnPort ReadEn;
  WriteEnPort WriteEn;
  OneHotDataGroup QM[15:0] {
    Instance BlockA_I1 Of BlockA {
      AddressValue 16'h0000;
    }
    Instance BlockA_I2 Of BlockA {
      AddressValue 16'h2300;
    }
  }
// Default DataIn mapping is right justified
// Can be explicitly specified with classic OneHotDataGroup syntax:
OneHotDataGroup Q[15:0] {
  Port BlockA_I1.DOH[7:0];
  Port BlockA_I1.DOL[0:7];
}

}
Module GreyBox1 {
  ScanInPort SI; CaptureEnPort Ce; ShiftEnPort Se;
  UpdateEnPort Ue; SelectPort Sel; ResetPort Rst;
  TCKPort Tck; ScanOutPort SO { Source Sib.so; }

  Instance tdr1a Of tdr { 
    InputPort SI = SI; InputPort CE = Ce; InputPort SE = Se;
    InputPort UE = Ue; InputPort SEL = Sib1.ten; 
    InputPort RST = Rst; InputPort DI = I1.DO; InputPort TCK = Tck;
  }
  Instance I1 Of Instrument { InputPort DI = tdr1a.DO; }
  
  Instance Sib Of sib { 
    InputPort si = SI; InputPort ce = Ce; InputPort se = Se;
    InputPort ue = Ue; InputPort sel = Sel; InputPort rst = Rst;
    InputPort fso = tdr1a.SO; InputPort tck = Tck; 
  }
}

Module BlackBox1 {
  ScanInPort SI; CaptureEnPort Ce; ShiftEnPort Se;
  UpdateEnPort Ue; SelectPort Sel; ResetPort Rst;
  TCKPort Tck; ScanOutPort SO;
}

Module GreyBox2 {
  ScanInPort SI; CaptureEnPort Ce; ShiftEnPort Se;
  UpdateEnPort Ue; SelectPort Sel; ResetPort Rst;
  TCKPort Tck; ScanOutPort SO { Source Sib2.so; }
  Instance tdr2a Of tdr { 
    InputPort SI = SI; InputPort CE = Ce; InputPort SE = Se;
    InputPort UE = Ue; InputPort SEL = Sel; 
    InputPort RST = Rst; InputPort DI = I1.DO; InputPort TCK = Tck;
  }
  Instance tdr2b Of tdr { 
    InputPort SI = tdr2a.so; InputPort CE = Ce; InputPort SE = Se;
    InputPort UE = Ue; InputPort SEL = Sib1.ten; 
    InputPort RST = Rst; InputPort DI = I2.DO; InputPort TCK = Tck;
  }
  Instance tdr2c Of tdr { 
    InputPort SI = Sib1.so; InputPort CE = Ce; InputPort SE = Se;
    InputPort UE = Ue; InputPort SEL = Sib2.ten; 
    InputPort RST = Rst; InputPort DI = I3.DO; InputPort TCK = Tck;
  }
  Instance I1 Of Instrument { InputPort DI = tdr2a.DO; }
  Instance I2 Of Instrument { InputPort DI = tdr2b.DO; }
  Instance I3 Of Instrument { InputPort DI = tdr2c.DO; }
  
Instance Sib1 Of sib { 
    InputPort si = tdr2a.so; InputPort ce = Ce; InputPort se = Se;
    InputPort ue = Ue; InputPort sel = Sel; InputPort rst = Rst;
    InputPort fso = tdr2b.SO; InputPort tck = Tck;
  }
  Instance Sib2 Of sib { 
    InputPort si = tdr2b.so; InputPort ce = Ce; InputPort se = Se;
    InputPort ue = Ue; InputPort sel = Sel; InputPort rst = Rst;
    InputPort fso = tdr2c.SO; InputPort tck = Tck;
  }
} 

Module SIwide {
ScanInterface wide {
  Chain c1 {
    Port si1;
    Port so1;
    DefaultLoadValue 3'b0;
  }
  Chain c2 {
    Port si2;
    Port so2;
    DefaultLoadValue 5'b0;
  }
  Chain c3 {
    Port si3;
    Port so3;
    DefaultLoadValue 7'b0;
  }
  Port selw;
  Port sel;
}
ScanInterface narrow1 {
  Port si1;
  Port so1;
  Port seln1;
  Port sel;
  DefaultLoadValue 13'b0;
}
ScanInterface narrow2 {
  Port si1;
  Port so3;
  Port seln2;
  Port sel;
  DefaultLoadValue 7'b0;

}
}


