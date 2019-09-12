
Module Daisy_3WI {
ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
UpdateEnPort UE; SelectPort SEL; ResetPort RST;
TCKPort TCK; ScanOutPort SO { Source WI3.SO; }
Instance WI1 Of WrappedInstr { InputPort SI = SI; }
Instance WI2 Of WrappedInstr { InputPort SI = WI1.SO; }
Instance WI3 Of WrappedInstr { InputPort SI = WI2.SO; }
}
