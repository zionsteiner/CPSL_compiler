//
// Created by zion on 4/6/20.
//

#include <iostream>
#include <classes/Expr/ConstExpr/ConstExpr.h>
#include "Symbol.h"
#include "globals.h"

Symbol::Symbol(Expr* expr, Type* type) {
    this->expr = expr;
    this->offset = -1;
    this->type = type;
}

Symbol::Symbol(int offset, Type* type) {
    this->offset = offset;
    this->expr = nullptr;
    this->type = type;
}

Symbol::Symbol(const Expr* expr, Type* type) {
    this->expr = const_cast<Expr *>(expr);
    this->offset = -1;
    this->type = type;
}

RegisterPool::Register Symbol::emitMips() {
    RegisterPool::Register reg;
    // Const
    if (expr != nullptr) {
        auto constExpr = dynamic_cast<ConstExpr*>(expr);
        if (constExpr != nullptr) {
            reg = constExpr->emitMips();
        } else {
            throw "Expected constExpr, got something else in Symbol::emitMips()";
        }
    // Variable
    } else if (offset != -1) {
        reg = registerPool.get();
        std::string mips = "lw " + reg.getRegId() + ", " + std::to_string(offset) + "(" + symbolTable.getBaseReg() + ")";
        std::cout << mips << std::endl;
    } else {
        throw "Not const nor variable stored in symbol";
    }

    return reg;
}
