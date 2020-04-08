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
    std::string id = lVal->id->id;
    auto symbol = symbolTable.lookupSymbol(id);
    int offset = symbol->offset;

    if (offset != -1) {
        auto reg = expr->emitMips();
        std::cout << "# Assignment" << std::endl;
        std::cout << "sw " + reg.getRegId() + " " + std::to_string(offset) + "(" + symbolTable.getBaseReg() + ")" << std::endl;
    } else {
        throw std::invalid_argument("ERROR: attempt to assign to non-var");
    }
}