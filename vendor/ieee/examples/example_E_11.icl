Module Block1_slide24 {
ScanInPort SI; CaptureEnPort Ce; ShiftEnPort Se;
UpdateEnPort Ue; SelectPort Sel; ResetPort Rst;
TCKPort Tck; ScanOutPort SO { Source M3; }
DataInPort tdr4_q[2:0];
Instance tdr1 Of tdr { InputPort SI = SI; InputPort DI = I1.DO; }
Instance tdr2 Of tdr { InputPort SI = M1; InputPort DI = I2.DO; }
Instance tdr3 Of tdr { InputPort SI = M2; InputPort DI = I3.DO; }
Instance I1 Of Instrument { InputPort DI = tdr1.DO; }
Instance I2 Of Instrument { InputPort DI = tdr2.DO; }
Instance I3 Of Instrument { InputPort DI = tdr3.DO; }
ScanMux M1 SelectedBy tdr4_q[2] {1'b0 : SI; 1'b1 : tdr1.SO; }
ScanMux M2 SelectedBy tdr4_q[1] {1'b0 : M1; 1'b1 : tdr2.SO; }
ScanMux M3 SelectedBy tdr4_q[0] {1'b0 : M2; 1'b1 : tdr3.SO; }
}
Module Block2_slide24 {
ScanInPort SI2; CaptureEnPort Ce2; ShiftEnPort Se2; UpdateEnPort Ue2;
SelectPort Sel2; ResetPort Rst; TCKPort Tck; ScanOutPort SO2 { Source
tdr4[0]; } DataOutPort tdr4_q[2:0] {Source tdr4; }
ScanRegister tdr4[2:0] {ScanInSource SI2; CaptureSource 3'b000;
ResetValue 3'b000;}
}
