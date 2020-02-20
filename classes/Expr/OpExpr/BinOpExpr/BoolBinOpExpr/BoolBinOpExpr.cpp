//
// Created by zion on 2/17/20.
//

#include "BoolBinOpExpr.h"
#include "../../../Const/BoolConst.h"

BoolBinOpExpr::BoolBinOpExpr(Expr* a, Expr* b): BinOpExpr(a, b) {}

template<typename T>
Expr* BoolBinOpExpr::binOp(Expr* a, Expr* b) {
    if (a->isCompVal() && b->isCompVal()) {
        BoolConst* a = dynamic_cast<BoolConst*> a;
        BoolConst* b = dynamic_cast<BoolConst*> b;
        auto val = T::binOp(a->value, b->value);
        delete a;
        delete b;

        return new BoolConst(val);
    } else {
        return new T(a, b);
    }
}