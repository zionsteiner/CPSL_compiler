//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <globals.h>
#include "ChrConstExpr.h"

ChrConstExpr::ChrConstExpr(char value): ConstExpr(CHR_T), value(value) {}

std::string ChrConstExpr::toString() const {
    std::string retStr;
    switch (value) {
        case '\n': retStr = "\\n";
                   break;
        case '\r': retStr = "\\r";
                   break;
        case '\b': retStr = "\\b";
                   break;
        case '\t': retStr = "\\t";
                   break;
        case '\f': retStr = "\\f";
                   break;
        default: retStr = std::string(1, value);
                 break;
    }

    return retStr;
}

RegisterPool::Register ChrConstExpr::emitMips() {
    auto reg = registerPool.get();
    std::string mips = "li " + reg.getRegId() + ", " + "'" + toString() + "'";
    std::cout << mips << std::endl;

    return reg;
}