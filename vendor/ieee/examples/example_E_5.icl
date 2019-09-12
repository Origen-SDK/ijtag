
Module WrappedInstr {
ScanInPort SI;
ScanOutPort SO { Source reg1.SO;}
ShiftEnPort SE;
CaptureEnPort CE;
UpdateEnPort UE;
SelectPort SEL;
ResetPort RST;
TCKPort TCK;
ScanInterface scan_client { Port SI; Port SO; Port SEL; }
Instance I1 Of Instrument {
InputPort DI = reg1.DO; InputPort TCK = Tck;
}
Instance reg1 Of SReg {
InputPort SI = SI; InputPort DI = I1.DO;
}
}
