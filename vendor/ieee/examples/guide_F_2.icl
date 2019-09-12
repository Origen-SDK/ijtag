Module SReg3 {
ScanInPort SI;
CaptureEnPort CE;
ShiftEnPort SE;
CaptureEnPort CE;
UpdateEnPort UE;
SelectPort SEL;
ResetPort RST;
TCKPort TCK;
ScanOutPort SO { Source SR[0]; LaunchEdge Rising; }
DataInPort DI[2:0];
DataOutPort DO[2:0] { Source SR; }
ScanInterface SReg_client { Port SI; Port SO; Port SEL; }
ScanRegister SR[2:0] {
ScanInSource SI; CaptureSource DI; ResetValue 3'b000;
}
}
