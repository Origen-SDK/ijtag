#include <string>
#include "antlr4-runtime.h"
#include "iclBaseVisitor.h"
#include "iclGraph.hpp"

namespace IJTAG {

class  iclGraphVisitor : iclBaseVisitor {
public:    
  antlrcpp::Any visitIcl_source(iclParser::Icl_sourceContext *ctx);

	antlrcpp::Any visitInputPort_connection(iclParser::InputPort_connectionContext *ctx);	
};

}
