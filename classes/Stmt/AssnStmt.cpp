//
// Created by zion on 2/27/20.
//

#include <globals.h>
#include <iostream>
#include "AssnStmt.h"

AssnStmt::AssnStmt(LValue* lVal, Expr* expr): lVal(lVal), expr(expr) {}

std::string AssnStmt::toString() const {
    return lVal->toString() + " := " + expr->toString();
}

void AssnStmt::emitMips() {
    int baseOffset = lVal->lookupBaseOffset();

    if (baseOffset != -1) {
        std::cout << "# Assignment" << std::endl;
        auto lValAddrReg = lVal->emitAddr();
        auto reg = expr->emitMips();
        std::cout << "sw " + reg.getRegId() + ", (" + lValAddrReg.getRegId() + ")" << std::endl;
    } else {
        throw std::invalid_argument("ERROR: attempt to assign to non-var");
    }
}