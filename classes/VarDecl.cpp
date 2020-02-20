//
// Created by zion on 2/20/20.
//

#include "VarDecl.h"

VarDecl::VarDecl(VarAssignList* list): list(list) {}
std::string VarDecl::toString() const {
    return "var " + list->toString();
}