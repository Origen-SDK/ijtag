#include <string>
#include "antlr4-runtime.h"
#include "iclBaseVisitor.h"
#include "iclGraph.hpp"
#include <boost/graph/adjacency_list.hpp>

namespace IJTAG {

class  iclGraphVisitor : iclBaseVisitor {

  typedef boost::adjacency_list<boost::vecS, boost::vecS,
                            boost::directedS,
                            boost::no_property,
                            boost::no_property
                            > IclASTGraph;

  IclASTGraph G;

public:    
  iclGraphVisitor();

  antlrcpp::Any visitIcl_source(iclParser::Icl_sourceContext *ctx);

	antlrcpp::Any visitInputPort_connection(iclParser::InputPort_connectionContext *ctx);	

	antlrcpp::Any visitInstance_def(iclParser::Instance_defContext *ctx);	
};

}
