#pragma once

#include <string>

using namespace std;

namespace IJTAG {

class iclAPI {
  string _file;

public:
  iclAPI(string file);
  string file();
  void parse();

};

}
