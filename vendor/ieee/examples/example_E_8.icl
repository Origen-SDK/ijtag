
Module Single_SIB_3WI {
ScanInPort SI; CaptureEnPort CE; ShiftEnPort SE;
UpdateEnPort UE; SelectPort SEL; ResetPort RST;
TCKPort TCK; ScanOutPort SO { Source SIB1.SO; }
Instance SIB1 Of SIB_mux_pre { InputPort SI = SI;
InputPort fromSO = WI3.SO; }
Instance WI1 Of WrappedInstr { InputPort SI = SIB1.toSI; }
Instance WI2 Of WrappedInstr { InputPort SI = WI1.SO; }
Instance WI3 Of WrappedInstr { InputPort SI = WI2.SO; }
}
