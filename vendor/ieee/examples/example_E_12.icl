Module Block1_slide36 {
ScanInPort SI; CaptureEnPort Ce; ShiftEnPort Se;
UpdateEnPort Ue; SelectPort Sel; ResetPort Rst;
TCKPort Tck; ScanOutPort SO { Source tdr4[0]; }
Instance tdr1 Of tdr { InputPort SI = SI; InputPort DI = I1.DO; }
Instance tdr2 Of tdr { InputPort SI = SI; InputPort DI = I2.DO; }
Instance tdr3 Of tdr { InputPort SI = SI; InputPort DI = I3.DO; }
Instance I1 Of Instrument { InputPort DI = tdr1.DO; }
Instance I2 Of Instrument { InputPort DI = tdr2.DO; }
Instance I3 Of Instrument { InputPort DI = tdr3.DO; }
ScanMux M4 SelectedBy tdr4[1:0] {2'b00 : SI;
2'b01 : tdr1.SO;
2'b10 : tdr2.SO;
2'b11 : tdr3.SO; }
ScanRegister tdr4[1:0] {ScanInSource M4;
CaptureSource 2'b00;
ResetValue 2'b00;}
}
