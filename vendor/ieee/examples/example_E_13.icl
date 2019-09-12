Module Block1_slide41 {
ScanInPort SI; CaptureEnPort Ce; ShiftEnPort Se;
UpdateEnPort Ue; SelectPort Sel; ResetPort Rst;
TCKPort Tck; ScanOutPort SO { Source tdr5[0]; }
Instance tdr1 Of tdr {
InputPort SI = SI; InputPort SEL = S1; InputPort DI = I1.DO;
// AllowBroadcastOnScanInterface tdr_client;
}
Instance tdr2 Of tdr {
InputPort SI = SI; InputPort SEL = S2; InputPort DI = I2.DO;
// AllowBroadcastOnScanInterface tdr_client;
}
Instance tdr3 Of tdr {
InputPort SI = SI; InputPort SEL = S3; InputPort DI = I3.DO;
// AllowBroadcastOnScanInterface tdr_client;
}
Instance I1 Of Instrument { InputPort DI = tdr1.DO; }
Instance I2 Of Instrument { InputPort DI = tdr2.DO; }
Instance I3 Of Instrument { InputPort DI = tdr3.DO; }
LogicSignal S1 {tdr5[1:0],Sel == 3'b0x1;}
LogicSignal S2 {tdr5[1:0],Sel == 3'bx01;}
LogicSignal S3 {tdr5[1:0],Sel == 3'b001 && tdr5[1:0],Sel == 3'b111;}
ScanMux M4 SelectedBy tdr5[1:0] {2'b00 : tdr1.SO;
2'b01 : tdr1.SO;
2'b10 : tdr2.SO;
2'b11 : tdr3.SO; }
ScanRegister tdr5[1:0] {ScanInSource M4;
CaptureSource 2'b00;
ResetValue 2'b00;}
}
