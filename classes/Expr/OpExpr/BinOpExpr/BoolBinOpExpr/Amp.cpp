//
// Created by zion on 2/17/20.
//

#include <globals.h>
#include <iostream>
#include "Amp.h"

Amp::Amp(Expr* a, Expr* b): BoolBinOpExpr(a, b) {}

bool Amp::binOp(int a, int b) {return a && b;}

std::string Amp::toString() const {
    return a->toString() + " & " + b->toString();
}

RegisterPool::Register Amp::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();
    auto regC = registerPool.get();

    std::cout << "# AND" << std::endl;
    std::cout << "seq " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;

    return regC;
}