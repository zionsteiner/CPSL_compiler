//
// Created by zion on 2/17/20.
//

#include <iostream>
#include "ChrConstExpr.h"

ChrConstExpr::ChrConstExpr(char value): value(value) {}
std::string ChrConstExpr::toString() const {
    return std::string(1, value);
}