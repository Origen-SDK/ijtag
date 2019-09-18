#pragma once

#include <string>

using namespace std;

namespace IJTAG {

class iclAPI {
  /// The top-level/entry file for this ICL network
  string _file;

public:
  iclAPI(string file);
  string file();
  void parse();

};

}
