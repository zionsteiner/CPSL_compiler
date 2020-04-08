//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <globals.h>
#include "StrConstExpr.h"

StrConstExpr::StrConstExpr(const char* value): ConstExpr(STR_T) {
    std::string tempStr(value);
    int strLen = tempStr.size();
    this->value = tempStr.substr(1, strLen - 2);
}

std::string StrConstExpr::toString() const {
    return "\"" + value + "\"";
}

RegisterPool::Register StrConstExpr::emitMips() {
    auto reg = registerPool.get();
    std::string strId = symbolTable.addString(value);

    std::cout << "# StrConstExpr" << std::endl;
    std::cout << "la " + reg.getRegId() + ", " + strId << std::endl;

    return reg;
}