//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>
#include <globals.h>

#include "Not.h"

Not::Not(Expr* expr): UnaryOpExpr(expr, BOOL_T) {}

Expr* Not::op(Expr* a) {
    if (a->isCompVal()) {
        auto a_new = dynamic_cast<BoolConstExpr*> (a);
        auto val = Not::op(a_new->value);

        return new BoolConstExpr(val);
    } else {
        return new Not(a);
    }
}

bool Not::op(bool a) {return !a;}
std::string Not::toString() const {
    return '~' + expr->toString();
}

RegisterPool::Register Not::emitMips() {
    auto regA = expr->emitMips();

    std::cout << "# Not" << std::endl;
    std::cout << "beq $0, " + regA.getRegId() + ", 3" << std::endl;
    auto regB = registerPool.get();
    std::cout << "li " + regB.getRegId() + ", 0" << std::endl;
    std::cout << "beq " + regA.getRegId() + ", " + regB.getRegId() + ", 2" << std::endl;
    std::cout << "li " + regA.getRegId() + ", 1" << std::endl;

    return regA;
}