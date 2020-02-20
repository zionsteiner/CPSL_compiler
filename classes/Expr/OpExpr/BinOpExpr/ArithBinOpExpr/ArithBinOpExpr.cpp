//
// Created by zion on 2/17/20.
//

#include "ArithBinOpExpr.h"
#include "../../../Const/IntConst.h"

ArithBinOpExpr::ArithBinOpExpr(Expr* a, Expr* b): BinOpExpr(a, b) {}

template<typename T>
Expr* ArithBinOpExpr::binOp(Expr* a, Expr* b) {
    if (a->isCompVal() && b->isCompVal()) {
        IntConst* a = dynamic_cast<IntConst*> a;
        IntConst* b = dynamic_cast<IntConst*> b;
        auto val = T::binOp(a->value, b->value);
        delete a;
        delete b;

        return new IntConst(val);
    } else {
        return new T(a, b);
    }
}