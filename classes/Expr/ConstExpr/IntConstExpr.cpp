//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>
#include <globals.h>
#include "IntConstExpr.h"

IntConstExpr::IntConstExpr(int value): ConstExpr(INT_T), value(value) {}

std::string IntConstExpr::toString() const {
    return std::to_string(value);
}

RegisterPool::Register IntConstExpr::emitMips() {
    auto reg = registerPool.get();
    std::string mips = "li " + reg.getRegId() + ", " + toString();
    std::cout << mips << std::endl;

    return reg;
}