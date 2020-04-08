//
// Created by zion on 2/17/20.
//

#include <sstream>
#include <globals.h>
#include "Geq.h"

Geq::Geq(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool Geq::binOp(int a, int b) {return a >= b;}
std::string Geq::toString() const {
    return a->toString() + " >= " + b->toString();
}

RegisterPool::Register Geq::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();
    auto regC = registerPool.get();

    std::cout << "# Geq" << std::endl;
    std::cout << "sge " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;

    return regC;
}
