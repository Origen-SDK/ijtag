Module InstA {
DataInPort DH[7:0];
DataInPort DL[7:0];
DataOutPort QH[7:0] { Source Q[15:8]; }
DataOutPort QL[7:0] { Source Q[7:0]; }
AddressPort AH[19:16];
AddressPort AL[15:0];
ReadEnPort RE; //One and only one RE/WE ports on
WriteEnPort WE; //modules containing addressable regs
OneHotDataGroup Q[15:0] {
DataRegister R0[15:0] {
AddressValue 8'd0;
}
DataRegister R1[15:0] {
AddressValue 8'd1;
}
// …
DataRegister R72[15:0] {
AddressValue 8'd72;
}
}
Alias Ena = R0[15];
Alias AMode[8:0] = R0[14:6] {
RefEnum Amodes;
}
//…
Alias RH = R72[0];
Enum AModes { M1 = 9'h0;// …; 
M9 = 9'h0A4; }
}
Module BlockA {
DataInPort D[15:0];
DataOutPort Q[15:0] { Source Q[15:0]; }
AddressPort A[19:0];
ReadEnPort ReadEn;
WriteEnPort WriteEn;
OneHotDataGroup Q[15:0] {
Instance BlockA_I1 Of BlockA {
AddressValue 16'h0000;
}
Instance BlockA_I2 Of BlockA {
AddressValue 16'h2300;
}
//…
}
// Default DataIn mapping is right justified
// Can be explicitely specified with classic OneHotDateGroup syntax:
OneHotDataGroup Q[15:0] {
Port BlockA_I1.DOH[7:0];
Port BlockA_I1.DOL[0:7];
//…
}
}
