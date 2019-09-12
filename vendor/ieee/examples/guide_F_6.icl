Module michele2chains {
// common control signals
ShiftEnPort SE;
CaptureEnPort CE;
UpdateEnPort UE;
TCKPort TCK;
ResetPort RST;
// red scan chain (sometimes yellow)
SelectPort RedSEL;
ScanInPort RedTDI; // “TDI” in yellow in figure
ScanOutPort RedTDO {
Source gateway_scan_reg2[0];
}
// blue scan chain
SelectPort BlueSEL;
ScanInPort BlueTDI; // “BTDI” in figure
ScanOutPort BlueTDO {
Source SIB01.SO;
}
// elements on “gateway” scan chain
ScanRegister gateway_scan_reg1 { ScanInSource RTDI; }
Instance SIB00 Of DoubleSIB {
InputPort SI0 = gateway_scan_reg1;
InputPort SEL0 = RedSEL;
InputPort SI1 = BlueTDI;
InputPort SEL1 = BlueSEL;
InputPort FromSO = SIB11.SO;
}
ScanRegister gateway_scan_reg3 { ScanInSource SIB00.SO; }
Instance SIB01 Of DoubleSIB {
InputPort SI0 = gateway_scan_reg3[0];
InputPort SEL0 = RedSEL;
InputPort SI1 = EmbeddedSoC.SO1;
InputPort SEL1 = BlueSEL;
InputPort FromSO = EmbeddedSoC.SO0;
}
ScanRegister gateway_scan_reg2 { ScanInSource SIB01.SO; }
}
Module DoubleSIB {
// common control signals
ShiftEnPort SE;
CaptureEnPort CE;
UpdateEnPort UE;
TCKPort TCK;
ResetPort RST;
// first scan chain
SelectPort SEL0;
ScanInPort SI0;
// second scan chain
SelectPort SEL1;
ScanInPort SI1;
// SIB FromSO port
ScanInPort FromSO;
ScanOutPort SO {
Source SIBMux;
}
// elements
ScanMux InMux SelectedBy SEL0, SEL1 {
2'b10: SI0;
2'b01: SI1;
}
ScanRegister scan_reg { ScanInSource InMux; }
ScanMux SIBMux SelectedBy scan_reg {
1'b10: scan_reg;
1'b01: FromSO;
}
}
Module COREA {
ScanInPort SI1;
ScanInPort SI2;
SelectPort Sel1;
SelectPort Sel2;
ScanOutPort SO {Source SIB;}
//...
ScanRegister regA[7:0] {
ScanInSource M1;
}
ScanRegister SIB {
ScanInSource M2;
ResetValue 1'b0;
}
ScanMux M1 SelectedBy Sel2 {
1'b0 : SI1;
1'b1 : SI2;
}
ScanMux M2 SelectedBy Sel2,SIB {
2'b01 : regA[0];
2'bxx : M1;
}
ScanInterface SP1 {Port SI1;Port Sel1;Port SO;}
ScanInterface SP2 {Port SI2;Port Sel2;Port SO;}
}
