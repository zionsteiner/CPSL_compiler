//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>
#include "IntConstExprExprExpr.h"

IntConstExprExpr::IntConstExprExpr(int value): value(value) {}
std::string IntConstExprExpr::toString() const {
    return std::to_string(value);
}