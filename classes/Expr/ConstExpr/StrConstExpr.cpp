//
// Created by zion on 2/17/20.
//

#include <iostream>
#include "StrConstExpr.h"

StrConstExpr::StrConstExpr(const char* value): value(value) {}

std::string StrConstExpr::toString() const {
    return value;
}