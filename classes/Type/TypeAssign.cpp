//
// Created by zion on 3/12/20.
//

#include "TypeAssign.h"

TypeAssign::TypeAssign(Ident* id, Type* type): id(id), type(type) {}
std::string TypeAssign::toString() const {return id->toString() + type->toString();}