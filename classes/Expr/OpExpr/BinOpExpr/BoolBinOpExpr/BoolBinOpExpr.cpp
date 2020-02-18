//
// Created by zion on 2/17/20.
//

#include "BoolBinOpExpr.h"

BoolBinOpExpr::BoolBinOpExpr(Expr* a, Expr* b): BinOpExpr(a, b) {}

template<typename T>
static Expr* BoolBinOpExpr::binOp(Expr* a, Expr* b) {
    if (a->isCompVal() && b->isCompVal()) {
        auto val = T::binOp(a->value, b->value);
        delete a;
        delete b;
        return new BoolConst(val);
    } else {
        return new T(a, b);
    }
}