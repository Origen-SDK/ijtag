#include "iclGraphVisitor.hpp"

using namespace std;

namespace IJTAG {

iclGraphVisitor::iclGraphVisitor() {
}

antlrcpp::Any iclGraphVisitor::visitIcl_source(iclParser::Icl_sourceContext *ctx) {
  //vector<Element> elements;
  //
  //for (auto element : ctx->elements) {                
	////antlrcpp::Any el = visitAction(element);

  ////    elements.push_back(el);		
  //}    
      	
  //antlrcpp::Any result = Scene(ctx->name()->NAME()->getText(), elements);
  antlrcpp::Any result = iclGraph();

  visitChildren(ctx);

  return result;
}

antlrcpp::Any iclGraphVisitor::visitInstance_def(iclParser::Instance_defContext *ctx) {
  cout << "Instance: " << ctx->instance_name()->getText() << endl;
  visitChildren(ctx);
  return ctx;
}

antlrcpp::Any iclGraphVisitor::visitInputPort_connection(iclParser::InputPort_connectionContext *ctx) {
  //cout << "yo" << ctx->getText() << endl;
  cout << ctx->inputPort_name()->port_name()->getText() << endl;
  return ctx;
}

}
