//
// Created by zion on 2/19/20.
//

#include "VarAssign.h"

VarAssign::VarAssign(idList* idList, Type* type): idList(idList), type(type) {}
std::string VarAssign::toString() const {
    return idList->toString() + ": " + type->toString() + ';';
}
VarAssign::~VarAssign() {
    delete idList;
}
