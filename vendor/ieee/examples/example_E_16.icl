Module MBIST_engine {
DataInPort Cntl[3:0];
DataInPort Go;
DataOutPort Status[1:0];
DataOutPort State[3:0];
}
Module Memory {
DataOutPort fail_location[7:0];
DataOutPort fall_data[15:0];
}
