Module SingleTDR {
ScanInPort SI;
ShiftEnPort SE;
CaptureEnPort CE;
UpdateEnPort UE;
TCKPort TCK;
ResetPort RST;
SelectPort SEL;
ScanOutPort SO {
Source scan_reg24[0];
}
ScanRegister scan_reg24[23:0] { ScanInSource SI; }
}
