//
// Created by zion on 2/17/20.
//

#include "UnaryMinus.h"

UnaryMinus::UnaryMinus(Expr* a): UnaryOpExpr(a) {}
Expr* UnaryMinus::op(Expr* a) {
    if (a->isCompVal()) {
        IntConst* a = dynamic_cast<IntConst*> (a);
        auto val = UnaryMinus.op(a);
        delete a;

        return new IntConst(a);
    } else {
        return new UnaryMinus(a);
    }
}
int UnaryMinus::op(int a) {return -a;}
std::string UnaryMinus::toString() const {
    return '-' + a->toString();
}
