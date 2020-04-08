//
// Created by zion on 2/17/20.
//

#include <sstream>
#include <globals.h>
#include "Neq.h"

Neq::Neq(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}

bool Neq::binOp(int a, int b) {return a != b;}

std::string Neq::toString() const {
    return a->toString() + " <> " + b->toString();
}

RegisterPool::Register Neq::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();
    auto regC = registerPool.get();

    std::cout << "# Neq" << std::endl;
    std::cout << "sne " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;

    return regC;
}