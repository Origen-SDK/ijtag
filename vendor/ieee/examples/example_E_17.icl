Module MBIST_engine {
DataInPort Cntl[3:0];
DataInPort Go;
DataOutPort Status[1:0];
DataOutPort State[3:0];
}
Module Memory {
DataOutPort fail_location[7:0];
DataOutPort fail_data[15:0];
}
Module BISTed_Memory {
DataInPort Cntl[3:0];
DataInPort Go;
DataOutPort Status[1:0] {
Source BIST1.Status; } // is the “Inst.Port” format correct here?
DataOutPort State[3:0] {
Source BIST1.State; }
DataOutPort fail_location[7:0] {
Source Mem1.fail_location; }
DataOutPort fail_data[15:0] {
Source Mem1.fail_data; }
Instance BIST1 Of MBIST_engine {
InputPort Cntl = Cntl;
InputPort Go = Go;
}
Instance Mem1 Of Memory;
}
