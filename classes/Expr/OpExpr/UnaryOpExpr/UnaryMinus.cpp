//
// Created by zion on 2/17/20.
//

#include "UnaryMinus.h"

UnaryMinus::UnaryMinus(Expr* expr): UnaryOpExpr(expr) {}
Expr* UnaryMinus::op(Expr* a) {
    if (a->isCompVal()) {
        IntConstExpr* a_new = dynamic_cast<IntConstExpr*> (a);
        auto val = UnaryMinus::op(a_new->value);
        delete a_new;

        return new IntConstExpr(val);
    } else {
        return new UnaryMinus(a);
    }
}
int UnaryMinus::op(int a) {return -a;}
std::string UnaryMinus::toString() const {
    return '-' + expr->toString();
}
