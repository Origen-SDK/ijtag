
//Addressable type
Module M1 {
//logicalDataIn_signal is byte1[7:0], byte0[7:0]
DataInPort byteIn1[7:0];
DataInPort byteIn0[7:0];
// logicalAddress_signal is AddHigh[3:0], AddLow[7:0]
AddressPort AddHigh[3:0];
AddressPort AddLow[7:0];
ReadEnPort re;
WriteEnPort we;
// data out source is explicite do order is not relevant
DataOutPort byteOut0[7:0] { Source M1[7:0];}
DataOutPort byteOut1[7:0] { Source M1[15:8];}
OneHotDataGroup M1[15:0] {
// computed_address of M2.R1 = 1000 + 001 = 1001
Instance I1 Of M2 { AddressValue 'h1000; }
Instance I2 Of M2 { AddressValue 'h2000; }
DataRegister R1 { AddressValue 'h3001; }
DataRegister R2 { AddressValue 'h3002; }
}
}
Module M2 {
DataInPort dataIn[11:0];
AddressPort addIn [11:0];
ReadEnPort re;
WriteEnPort we;
DataOutPort dataOut[11:0] { Source M1;}
OneHotDataGroup M1[11:0] {
DataRegister R1 { AddressValue 'h001; }
DataRegister R2 { AddressValue 'h002; }
}
}
// callback type
// Need to have defined an iProc named read_proc and write_proc following
// iProcForModule XXX where XXX match the value of the callback_namespace
// parameter in ICL
Module M1 {
Parameter callback_namespace = "M1";
DataRegister R1 {
ReadDataSource u1.dout[7:0];
ReadCallBack $callback_namespace read_proc <D> <R>;
}
DataRegister W1 {
WriteCallBack $callback_namespace write_proc <D> <R>;
}
}

//Illustates the cascading of OneHotScanGroups
Module M1 {
ScanOutPort SO { Source M1; }
OneHotScanGroup M1 {
Port child1.SO;
Port child2.SO;
Port child3.SO;
}
Instance child1 Of M2 {
//...
}
Instance child2 Of M2 {
//...
}
Instance child3 Of M2 {
//...
}
}
Module M2 {
ScanOutPort SO { Source M1; }
OneHotScanGroup M1 {
Port child1.SO;
Port child2.SO;
Port child3.SO;
}
Instance child1 Of M3 {
//...
}
Instance child2 Of M3 { //...}
}
Instance child3 Of M3 { //...}
}
}
Module M3 {
ScanOutPort SO {
Source R1[0];
Enable En1;
}
}

Module my_block {
Parameter myStringParam = "default";
Parameter nspace = "default";
Parameter pname = "myproc";
Parameter ss = "default";
Parameter MSB1 = 1;
Parameter MSB2 = $width-1;
Parameter width = 32;
Parameter CC = 1;
Parameter CS = $MSB2, 1'b0;
//. . .
Attribute att1 = "$myStringParam";
ScanRegister A[$MSB1:0] {
CaptureSource $CS;
//. . .
}
ScanRegister B[$width-1:0];
DataRegister D[$MSB2:0] {
//. . .
ReadCallBack $nspace $pname <R> <D> $ss $CC;
}
}
Module top {
//. . .
LocalParameter ABC = 4;
//. . .
Instance I1 Of my_block {
//. . .
Parameter my = "My";
Parameter string = "String";
Parameter myStringParam = $my,$string;
Parameter MSB2 = 31; // A defined as A[31:0] in my_block
Parameter MSB2 = 11; // D defined as D[11:0]
Parameter nspace = "mynspace";
Parameter pname = "myproc";
Parameter ss = "125 5'b0"; // ReadCallBack myproc <R><D> 125 5'b0 $CC;
Parameter CC = 4;
// ReadCallBack for this instance is now:
// ReadCallBack mynspace myproc <R><D> 125 5'b0 4;
//. . .
}
}

