NameSpace; // set the root name space as default for module declarations
UseNameSpace NS1; // remember, this is for instances, not module definitions
Module ABC { // defined in the root name space.
Instance i1 Of myModule; // module from NS1 (since it was set to be default via UseNameSpace)
Instance i2 Of myModule; // same module from NS1
Instance i3 Of myModule; // same module from NS1
Instance i4 Of ::myModule; // different module (but with the same name) from the root name space
}

NameSpace NS1 ;
Module ABC { // now defined in the NS1 name space
Instance i1 Of myModule; // module from NS1
Instance i2 Of ::myModule; // module with the same name from the root name space
}

NameSpace NS1 ;
UseNameSpace NS2;
Module ABC { // now defined in the NS1 name space.
Instance i1 Of myModule; // module from NS2
Instance i2 Of ::myModule; // module with the same name from the root name space
}

//File 1:
Module ex1 { // defined in root name space.
Instance ex2_inst Of ex2; // definition take from root name space.
}
NameSpace ex1ns;
Module ex1 { // defined in ex1ns name space.
Instance ex2_inst Of ex2; // definition taken from ex1ns.
UseNameSpace; // instantiation name space set to root.
Instance ex2_inst_2 Of ex2; // definition taken from root name space.
Instance ex2 Of ex2ns::ex2; // definition taken from ex2ns name space.
}
Module ex2 {} // defined in ex1ns name space
Module ex3 {
Instance ex2_inst Of ex2; //definition taken from ex1ns name space;
}
//File 2:
Module ex2 {} // defined in root name space
NameSpace ex2ns;
Module ex2 {} // defined in ex2ns name space
