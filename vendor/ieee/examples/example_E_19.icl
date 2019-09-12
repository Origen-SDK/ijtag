Module MBIST_engine {
DataInPort Cntl[3:0];
DataInPort Go;
DataOutPort Status[1:0];
DataOutPort State[3:0];
}
Module ScannedMemory {
ScanInPort SI;
ShiftEnPort SE;
CaptureEnPort CE;
UpdateEnPort UE;
TCKPort TCK;
ResetPort RST;
SelectPort SEL;
ScanOutPort SO {
Source f_data[0];
}
ScanRegister f_loc[7:0] { ScanInSource SI; }
ScanRegister f_data[15:0] { ScanInSource f_loc[0]; } // consider making these registers capture-only, since they correspond to the previously output-only ports…
}
Module BISTed_Memory {
DataInPort Cntl[3:0];
DataInPort Go;
DataOutPort Status[1:0] {
 Source BIST1.Status; }
DataOutPort State[3:0] {
 Source BIST1.State; }
ScanInPort SI;
ShiftEnPort SE;
CaptureEnPort CE;
UpdateEnPort UE;
TCKPort TCK;
ResetPort RST;
SelectPort SEL;
ScanOutPort SO {
Source Mem1.SO;
}
Instance BIST1 Of MBIST_engine {
InputPort Cntl = Cntl;
InputPort Go = Go;
}
Instance Mem1 Of Memory {
InputPort SI = SI;
InputPort SE = SE;
InputPort CE = CE;
InputPort UE = UE;
InputPort TCK = TCK;
InputPort RST = RST;
InputPort SEL = SEL;
}
}
