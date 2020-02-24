//
// Created by zion on 2/23/20.
//

#include "LValue.h"

LValue::LValue(Ident* id, DotOrIndexPlus* exts): id(id), exts(exts) {}
std::string LValue::toString() const {
    return id->toString() + exts->toString();
}
bool LValue::isCompVal() {
    return false;
}
