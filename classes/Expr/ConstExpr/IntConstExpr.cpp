//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>
#include "IntConstExpr.h"

IntConstExpr::IntConstExpr(int value): value(value) {}
std::string IntConstExpr::toString() const {
    return std::to_string(value);
}