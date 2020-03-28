//
// Created by zion on 2/18/20.
//

#include "SimpleType.h"

SimpleType::SimpleType(Ident* id): id(id) {}

std::string SimpleType::toString() const {return id->toString();}

int SimpleType::size() {return id->toString().size();}