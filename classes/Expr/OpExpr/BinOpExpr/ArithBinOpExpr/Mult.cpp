//
// Created by zion on 2/17/20.
//

#include <sstream>
#include <globals.h>
#include <iostream>
#include "Mult.h"

Mult::Mult(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}

int Mult::binOp(int a, int b) {return a * b;}

std::string Mult::toString() const {
    return "(" + a->toString() + " * " + b->toString() + ")";
}

RegisterPool::Register Mult::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();
    auto regC = registerPool.get();

    std::cout << "# Mult" << std::endl;
    std::cout << "mult " + regA.getRegId() + ", " + regB.getRegId() << std::endl;
    std::cout << "mflo " + regC.getRegId() << std::endl;

    return regC;
}