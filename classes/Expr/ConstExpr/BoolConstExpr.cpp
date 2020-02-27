//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>
#include "BoolConstExprExpr.h"

BoolConstExpr::BoolConstExpr(bool value): value(value) {}
std::string BoolConstExpr::toString() const {
    std::stringstream buffer;
    buffer << value;

    return buffer.str();
}
