//
// Created by zion on 2/17/20.
//

#include <sstream>
#include <iostream>
#include <globals.h>
#include "Div.h"

Div::Div(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}
int Div::binOp(int a, int b) {
    if (b == 0) {
        throw "Cannot divide by zero";
    } else {
        return a / b;
    }
}

std::string Div::toString() const {
    return "(" + a->toString() + " / " + b->toString() + ")";
}

RegisterPool::Register Div::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();
    auto regC = registerPool.get();

    std::cout << "# Div" << std::endl;
    std::cout << "div " + regA.getRegId() + ", " + regB.getRegId() << std::endl;
    std::cout << "mflo " + regC.getRegId() << std::endl;

    return regC;
}
