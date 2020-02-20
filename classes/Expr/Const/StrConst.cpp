//
// Created by zion on 2/17/20.
//

#include <iostream>
#include "StrConst.h"

StrConst::StrConst(char* value): value(value) {}

std::string StrConst::toString() const {
    return value;
}