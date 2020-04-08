//
// Created by zion on 2/17/20.
//

#include <sstream>
#include <globals.h>
#include <iostream>
#include "Bar.h"
#include "Amp.h"

Bar::Bar(Expr* a, Expr* b): BoolBinOpExpr(a, b) {}

bool Bar::binOp(bool a, bool b) {return a || b;}

std::string Bar::toString() const {
    return a->toString() + " | " + b->toString();
}

RegisterPool::Register Bar::emitMips() {
    auto regA = a->emitMips();
    auto regB = b->emitMips();
    auto regC = registerPool.get();

    std::cout << "# Bar" << std::endl;
    std::cout << "add " + regC.getRegId() + ", " + regA.getRegId() + ", " + regB.getRegId() << std::endl;
    auto regD = registerPool.get();
    std::cout << "li " + regD.getRegId() + ", " + "0" << std::endl;
    std::cout << "sgt " + regC.getRegId() + ", " + regC.getRegId() + ", " + regD.getRegId() << std::endl;

    return regC;
}