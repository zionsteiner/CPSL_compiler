//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <globals.h>
#include "UnaryMinus.h"

UnaryMinus::UnaryMinus(Expr* expr): UnaryOpExpr(expr, INT_T) {}

Expr* UnaryMinus::op(Expr* a) {
    if (a->isCompVal()) {
        IntConstExpr* a_new = dynamic_cast<IntConstExpr*> (a);
        auto val = UnaryMinus::op(a_new->value);

        return new IntConstExpr(val);
    } else {
        return new UnaryMinus(a);
    }
}
int UnaryMinus::op(int a) {return -a;}
std::string UnaryMinus::toString() const {
    return '-' + expr->toString();
}

RegisterPool::Register UnaryMinus::emitMips() {
    auto regA = expr->emitMips();
    auto regB = registerPool.get();

    std::cout << "# UnaryMinus" << std::endl;
    std::cout << "sub " + regB.getRegId() + ", $0, " + regA.getRegId() << std::endl;

    return regB;
}