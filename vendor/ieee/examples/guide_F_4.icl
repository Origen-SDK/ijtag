Module SIB_mux_post {
ScanInPort SI;
CaptureEnPort CE;
ShiftEnPort SE;
UpdateEnPort UE;
SelectPort SEL;
ResetPort RST;
TCKPort TCK;
ScanOutPort SO { Source SIBmux; LaunchEdge Rising; }
ScanInterface client {
Port SI; Port CE; Port SE; Port UE;
Port SEL; Port RST; Port TCK; Port SO;
}
ScanInPort fromSO;
ToCaptureEnPort toCE;
ToShiftEnPort toSE;
ToUpdateEnPort toUE;
ToSelectPort toSEL;
ToResetPort toRST;
ToTCKPort toTCK;
ScanOutPort toSI { Source SR; LaunchEdge Rising; }
ScanInterface host {
Port fromSO; Port toCE; Port toSE; Port toUE;
Port toSEL; Port toRST; Port toTCK; Port toSI;
}
ScanRegister SR {
ScanInSource SI; CaptureSource SR; ResetValue 1'b0;
}
ScanMux SIBmux SelectedBy SR {
1'b0 : SR;
1'b1 : fromSO;
}
}
