Module GreyBox1 {
ScanInPort SI; CaptureEnPort Ce; ShiftEnPort Se;
UpdateEnPort Ue; SelectPort Sel; ResetPort Rst;
TCKPort Tck; ScanOutPort SO { Source Sib.so; }
Instance tdr1a Of tdr {
InputPort SI = SI; InputPort CE = Ce; InputPort SE = Se;
InputPort UE = Ue; InputPort SEL = Sib1.ten;
InputPort RST = Rst; InputPort DI = I1.DO; InputPort TCK = Tck;
}
Instance I1 Of Instrument { InputPort DI = tdr1a.DO; }
Instance Sib Of sib {
InputPort si = SI; InputPort ce = Ce; InputPort se = Se;
InputPort ue = Ue; InputPort sel = Sel; InputPort rst = Rst;
InputPort fso = tdr1a.SO; InputPort tck = Tck;
}
}
Module BlackBox1 {
ScanInPort SI; CaptureEnPort Ce; ShiftEnPort Se;
UpdateEnPort Ue; SelectPort Sel; ResetPort Rst;
TCKPort Tck; ScanOutPort SO;
}

Module GreyBox2 {
ScanInPort SI; CaptureEnPort Ce; ShiftEnPort Se;
UpdateEnPort Ue; SelectPort Sel; ResetPort Rst;
TCKPort Tck; ScanOutPort SO { Source Sib2.so; }
Instance tdr2a Of tdr {
InputPort SI = SI; InputPort CE = Ce; InputPort SE = Se;
InputPort UE = Ue; InputPort SEL = Sel;
InputPort RST = Rst; InputPort DI = I1.DO; InputPort TCK = Tck;
}
Instance tdr2b Of tdr {
InputPort SI = tdr2a.so; InputPort CE = Ce; InputPort SE = Se;
InputPort UE = Ue; InputPort SEL = Sib1.ten;
InputPort RST = Rst; InputPort DI = I2.DO; InputPort TCK = Tck;
}
Instance tdr2c Of tdr {
InputPort SI = Sib1.so; InputPort CE = Ce; InputPort SE = Se;
InputPort UE = Ue; InputPort SEL = Sib2.ten;
InputPort RST = Rst; InputPort DI = I3.DO; InputPort TCK = Tck;
}
Instance I1 Of Instrument { InputPort DI = tdr2a.DO; }
Instance I2 Of Instrument { InputPort DI = tdr2b.DO; }
Instance I3 Of Instrument { InputPort DI = tdr2c.DO; }
Instance Sib1 Of sib {
InputPort si = tdr2a.so; InputPort ce = Ce; InputPort se = Se;
InputPort ue = Ue; InputPort sel = Sel; InputPort rst = Rst;
InputPort fso = tdr2b.SO; InputPort tck = Tck;
}
Instance Sib2 Of sib {
InputPort si = tdr2b.so; InputPort ce = Ce; InputPort se = Se;
InputPort ue = Ue; InputPort sel = Sel; InputPort rst = Rst;
InputPort fso = tdr2c.SO; InputPort tck = Tck;
}
}
