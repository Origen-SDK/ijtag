Module SRegLU {
ScanInPort SI;
CaptureEnPort CE;
ShiftEnPort SE;
CaptureEnPort CE;
UpdateEnPort UE;
SelectPort SEL;
ResetPort RST;
TCKPort TCK;
ScanOutPort SO { Source SR[0]; LaunchEdge Falling; }
DataInPort DI[0:0];
DataOutPort DO[0:0] { Source SR; }
ScanInterface SReg_client { Port SI; Port SO; Port SEL; }
ScanRegister SR[0:0] {
ScanInSource SI; CaptureSource DI; ResetValue 1'b0;
}
}
