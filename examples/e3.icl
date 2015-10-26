Module SReg {    
  ScanInPort      SI;
  ScanOutPort     SO { Source SR[0];}
  ShiftEnPort     SE;
  CaptureEnPort   CE;
  UpdateEnPort    UE;
  SelectPort      SEL;
  ResetPort       RST;
  TCKPort         TCK;
  DataInPort      DI[7:0];
  DataOutPort     DO[7:0] {Source SR; }
  ScanInterface   scan_client { Port SI; Port SO; Port SEL; }

  ScanRegister SR[7:0] { ScanInSource SI;
                         CaptureSource DI;
                         ResetValue 8'b00000000; }                   
}

Module SRegP1 {    
  Parameter MSB = 7;

  ScanInPort      SI;
  ScanOutPort     SO { Source SR[0];}
  ShiftEnPort     SE;
  CaptureEnPort   CE;
  UpdateEnPort    UE;
  SelectPort      SEL;
  ResetPort       RST;
  TCKPort         TCK;
  DataInPort      DI[$MSB:0];
  DataOutPort     DO[$MSB:0] {Source SR; }
  ScanInterface   scan_client { Port SI; Port SO; Port SEL; }

  ScanRegister SR[$MSB:0] { ScanInSource SI;
                            CaptureSource DI;
                            ResetValue 'b00000000; }                   
}

Module SRegP2 {
  Instance p1 of SRegP1 { Parameter MSB = 2; }
}

Module SRegP3 {    
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
