//
// Created by zion on 2/17/20.
//

#include <sstream>
#include <globals.h>
#include <iostream>
#include "Mod.h"

Mod::Mod(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}

int Mod::binOp(int a, int b) {return a % b;}

std::string Mod::toString() const {
    return "(" + a->toString() + " % " + b->toString() + ")";
}

RegisterPool::Register Mod::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();
    auto regC = registerPool.get();

    std::cout << "# Mod" << std::endl;
    std::cout << "div " + regA.getRegId() + ", " + regB.getRegId() << std::endl;
    std::cout << "mfhi " + regC.getRegId() << std::endl;

    return regC;
}