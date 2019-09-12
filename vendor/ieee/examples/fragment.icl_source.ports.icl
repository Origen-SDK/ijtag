Module blk1 {
CaptureEnPort CE[1:0];
DataInPort CapDis[1:0];
ToCaptureEnPort toCE[1:0] { Source u1.toCE, u0.toCE; }
Instance u0 Of CE_gating {
InputPort CE = CE[0];
InputPort CapDis = CapDis[0];
}
Instance u1 Of CE_gating {
InputPort CE = CE[1];
InputPort CapDis = CapDis[1];
}
}
Module CE_gating {
CaptureEnPort CE;
DataInPort CapDis;
ToCaptureEnPort toCE { Source ~CapDis; }
}
Module blk1 {
UpdateEnPort UE[1:0];
DataInPort UpdDis[1:0];
ToUpdateEnPort toUE[1:0] { Source u1.toUE, u0.toUE; }
Instance u0 Of UE_gating {
InputPort UE = UE[0];
InputPort UpdDis = UpdDis[0];
}
Instance u1 Of UE_gating {
InputPort UE = UE[1];
InputPort UpdDis = UpdDis[1];
}
}
Module UE_gating {
UpdateEnPort UE;
DataInPort UpdDis;
ToUpdateEnPort toUE { Source ~UpdDis; }
}
Module blk1 {
ResetPort higher_reset[1:0];
DataInPort local_reset[1:0];
ToUpdateEnPort toLower_reset[1:0] { Source u1.toRst, u0.toRst; }
Instance u0 Of RST_oring {
InputPort rst = higher_reset[0];
InputPort local_rst = local_reset[0];
}
Instance u1 Of RST_oring {
InputPort rst = higher_reset[1];
InputPort local_rst = local_reset[1];
}
}
Module RST_oring{
ResetPort rst;
DataInPort local_reset;
ToResetPort toRst { Source local_reset; }
}

Module TAP_FSM {
TCKPort tck;
TRSTPort trst;
TMSPort tms;
ToIRSelectPort irSel;
ToCaptureEnPort ce;
ToShiftEnPort ce;
ToUpdateEnPort ue;
}

Module botton_die {
ToTMSPort tms_to_upper_die;
// …
}

Module blk1 {
TMSPort tms[1:0];
DataInPort tms_en[1:0];
ToTMSPort toTms[1:0] { Source u1.totms, u0.toTms; }
Instance u0 Of TMS_gating {
InputPort tms = tms[0];
InputPort tms_en = tms_en[0];
}
Instance u1 Of TMS_gating {
InputPort tms = tms[1];
InputPort tms_en = tms_en[1];
}
}
Module TMS_gating {
TMSPort tms;
DataInPort tms_en;
ToTMSPort toTms { Source tms_en; }
}

Module M1 {
TCKPort TCK;
//…
}

Module botton_die {
ToTCKPort tck_to_upper_die;
//…
}

Module blk1 {
TRSTPort higher_trst[1:0];
DataInPort local_trst[1:0];
ToUpdateEnPort toLower_trst[1:0] { Source u1.toTrst, u0.toTrst; }
Instance u0 Of TRST_anding {
InputPort trst = higher_trst[0];
InputPort local_trst = local_trst[0];
}
Instance u1 Of TRST_anding {
InputPort trst = higher_trst[1];
InputPort local_trst = local_trst[1];
}
}
Module TRST_anding{
TRSTPort trst;
DataInPort local_trst;
ToTRSTPort toTrst { Source local_trst; }
}

Module M1 {
DataInPort In1;
DataInPort In2;
DataOutPort Out1 { Source I01.B; }
DataOutPort Out2 { Source I02.Z; }
Instance I01 Of M2 {
InputPort A = In2;
InputPort C = I02.Y;
}
Instance I02 Of M3 {
InputPort X = I01.B;
InputPort W = In1;
}
}
