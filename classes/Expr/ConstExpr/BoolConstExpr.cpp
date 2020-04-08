//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>
#include <globals.h>
#include "BoolConstExpr.h"

BoolConstExpr::BoolConstExpr(bool value): ConstExpr(BOOL_T), value(value) {}
std::string BoolConstExpr::toString() const {
    std::string retStr = value? "true": "false";

    return retStr;
}

RegisterPool::Register BoolConstExpr::emitMips() {
    auto reg = registerPool.get();
    std::string mips = "li " + reg.getRegId() + ", " + std::to_string((int)value);
    std::cout << mips << std::endl;

    return reg;
}
