// Implements the API exposed to Ruby via the class IJTAG::ICL
#include "iclAPI.hpp"
#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "iclLexer.h"
#include "iclParser.h"
#include "iclGraph.hpp"
#include "iclGraphVisitor.hpp"

using namespace antlr4;

namespace IJTAG {

iclAPI::iclAPI(string file) {
  _file = file;
}

string iclAPI::file() {
  return _file;
}

void iclAPI::parse() {
  ifstream stream;
  stream.open(_file);

  ANTLRInputStream input(stream);
  iclLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  iclParser parser(&tokens);    

  iclParser::Icl_sourceContext* tree = parser.icl_source();

  iclGraphVisitor visitor;
  iclGraph graph = visitor.visitIcl_source(tree);
  //visitor.visitIcl_source(tree);
}

}
