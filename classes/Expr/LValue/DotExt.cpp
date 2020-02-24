//
// Created by zion on 2/23/20.
//

#include "DotExt.h"

DotExt::DotExt(Ident* id): id(id) {}
std::string DotExt::toString() const {
    return '.' + id->toString();
}