#include <iostream>
#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "iclAPI.hpp"

using namespace Rice;

namespace IJTAG {

extern "C"
void Init_ijtag() {

  Module rb_mIJTAG = define_module("IJTAG");

  Data_Type<iclAPI> rb_cICL =
    define_class_under<iclAPI>(rb_mIJTAG, "ICL")
      .define_constructor(Constructor<iclAPI, string>())
      .define_method("file", &iclAPI::file)
      .define_method("parse", &iclAPI::parse);
}

}
