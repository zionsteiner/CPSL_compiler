//
// Created by zion on 2/17/20.
//

#include <sstream>
#include <globals.h>
#include "Leq.h"

Leq::Leq(Expr* expr1, Expr* expr2): CmprBinOpExpr(expr1, expr2) {}

bool Leq::binOp(int a, int b) {return a <= b;}

std::string Leq::toString() const {
    return a->toString() + " <= " + b->toString();
}

RegisterPool::Register Leq::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();
    auto regC = registerPool.get();

    std::cout << "# Leq" << std::endl;
    std::cout << "sle " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;

    return regC;
}
