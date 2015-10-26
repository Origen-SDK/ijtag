Module Instrument {
  DataInPort DI[(2+3)+2:0];
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
  Parameter Size = 8;

  ScanInPort      SI;
  ScanOutPort     SO { Source SR[0];}
  ShiftEnPort     SE;
  CaptureEnPort   CE;
  UpdateEnPort    UE;
  SelectPort      SEL;
  ResetPort       RST;
  TCKPort         TCK;
  DataInPort      DI[$Size-1:0];
  DataOutPort     DO[$Size-1:0] {Source SR; }
  ScanInterface   scan_client { Port SI; Port SO; Port SEL; }

  ScanRegister SR[$Size-1:0] { ScanInSource SI;
                               CaptureSource DI;
                               ResetValue $Size'b00000000; }                   
}

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
