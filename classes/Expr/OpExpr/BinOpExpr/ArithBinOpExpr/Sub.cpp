//
// Created by zion on 2/17/20.
//

#include <sstream>
#include <globals.h>
#include <iostream>
#include "Sub.h"

Sub::Sub(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}

int Sub::binOp(int a, int b) {return a - b;}

std::string Sub::toString() const {
    return "(" + a->toString() + " - " + b->toString() + ")";
}

RegisterPool::Register Sub::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();
    auto regC = registerPool.get();

    std::cout << "# Sub" << std::endl;
    std::cout << "sub " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;

    return regC;
}

RegisterPool::Register Sub::emitMips(Expr* expr1, Expr* expr2) {
    auto regA = expr1->emitMips();
    auto regB = expr2->emitMips();
    auto regC = registerPool.get();

    std::cout << "# Sub" << std::endl;
    std::cout << "sub " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;

    return regC;
}

RegisterPool::Register Sub::emitMips(RegisterPool::Register& regA, RegisterPool::Register& regB) {
    auto regC = registerPool.get();

    std::cout << "# Sub" << std::endl;
    std::cout << "sub " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;

    return regC;
}