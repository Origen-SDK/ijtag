Module Block1_slide21 {
ScanInPort SI; CaptureEnPort Ce; ShiftEnPort Se;
UpdateEnPort Ue; SelectPort Sel; ResetPort Rst;
TCKPort Tck; ScanOutPort SO { Source tdr4[0]; }
Instance tdr1 Of tdr { InputPort SI = SI; InputPort DI = I1.DO;}
Instance tdr2 Of tdr { InputPort SI = M1; InputPort DI = I2.DO;}
Instance tdr3 Of tdr { InputPort SI = M2; InputPort DI = I3.DO;}
Instance I1 Of Instrument { InputPort DI = tdr1.DO; }
Instance I2 Of Instrument { InputPort DI = tdr2.DO; }
Instance I3 Of Instrument { InputPort DI = tdr3.DO; }
// note the risk of long delay through mux-only chain
ScanMux M1 SelectedBy tdr4[2] {1'b0 : SI; 1'b1 : tdr1.SO; }
ScanMux M2 SelectedBy tdr4[1] {1'b0 : M1; 1'b1 : tdr2.SO; }
ScanMux M3 SelectedBy tdr4[0] {1'b0 : M2; 1'b1 : tdr3.SO; }
ScanRegister tdr4[2:0] {ScanInSource M3; CaptureSource 3'b000;
ResetValue 3'b000;}
}
