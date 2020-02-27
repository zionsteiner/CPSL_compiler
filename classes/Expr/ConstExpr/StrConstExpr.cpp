//
// Created by zion on 2/17/20.
//

#include <iostream>
#include "StrConstExpr.h"

StrConst::StrConst(char* value): value(value) {}

std::string StrConst::toString() const {
    return value;
}