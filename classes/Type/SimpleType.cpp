//
// Created by zion on 2/18/20.
//

#include "SimpleType.h"

SimpleType::SimpleType(Ident* id): id(id) {}

std::string toString() {return id->toString();}