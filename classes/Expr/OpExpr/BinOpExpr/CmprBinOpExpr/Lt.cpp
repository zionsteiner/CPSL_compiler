//
// Created by zion on 2/17/20.
//

#include <sstream>
#include <globals.h>
#include "Lt.h"

Lt::Lt(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}

bool Lt::binOp(int a, int b) {return a < b;}

std::string Lt::toString() const {
    return a->toString() + " < " + b->toString();
}

RegisterPool::Register Lt::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();
    auto regC = registerPool.get();

    std::cout << "# Lt" << std::endl;
    std::cout << "slt " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;

    return regC;
}