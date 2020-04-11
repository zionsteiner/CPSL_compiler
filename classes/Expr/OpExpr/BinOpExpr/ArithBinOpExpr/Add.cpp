//
// Created by zion on 2/14/20.
//

#include <iostream>
#include <sstream>
#include <globals.h>
#include "Add.h"

Add::Add(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}

int Add::binOp(int a, int b) {return a + b;}
std::string Add::toString() const {
    return "(" + a->toString() + " + " + b->toString() + ")";
}

RegisterPool::Register Add::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();

    auto regC = registerPool.get();
    std::cout << "# Add" << std::endl;
    std::cout << "add " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;

    return regC;
}

RegisterPool::Register Add::emitMips(RegisterPool::Register& regA, RegisterPool::Register& regB) {
    auto regC = registerPool.get();
    std::cout << "# Add" << std::endl;
    std::cout << "add " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;

    return regC;
}
