//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>
#include "ChrConstExpr.h"

ChrConst::ChrConst(char value): value(value) {}
std::string ChrConst::toString() const {
    return std::string(1, value);
}