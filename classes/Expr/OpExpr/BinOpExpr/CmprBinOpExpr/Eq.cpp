//
// Created by zion on 2/17/20.
//

#include <sstream>
#include <globals.h>
#include "Eq.h"

Eq::Eq(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool Eq::binOp(int a, int b) {return a == b;}
std::string Eq::toString() const {
    return a->toString() + " + " + b->toString();
}

RegisterPool::Register Eq::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();
    auto regC = registerPool.get();

    std::cout << "# EQ" << std::endl;
    std::cout << "seq " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;

    return regC;
}
