//
// Created by zion on 2/17/20.
//

#include <sstream>
#include <globals.h>
#include "Gt.h"

Gt::Gt(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}

bool Gt::binOp(int a, int b) {return a > b;}

std::string Gt::toString() const {
    return a->toString() + " > " + b->toString();
}

RegisterPool::Register Gt::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();
    auto regC = registerPool.get();

    std::cout << "# Gt" << std::endl;
    std::cout << "sgt " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;

    return regC;
}