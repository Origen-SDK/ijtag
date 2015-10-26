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

Module SRegParam {    
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
