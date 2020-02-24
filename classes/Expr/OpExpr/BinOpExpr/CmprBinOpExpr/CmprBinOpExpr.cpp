//
// Created by zion on 2/17/20.
//

#include "CmprBinOpExpr.h"
#include "../../../Const/BoolConst.h"

CmprBinOpExpr::CmprBinOpExpr(Expr* a, Expr* b): BinOpExpr(a, b) {}

template<typename T>
Expr* CmprBinOpExpr::binOp(Expr* a, Expr* b) {
    if (a->isCompVal() && b->isCompVal()) {
        auto a = dynamic_cast<BoolConst*> a;
        auto b = dynamic_cast<BoolConst*> b;
        auto val = T::binOp(a->value, b->value);
        delete a;
        delete b;

        return new BoolConst(val);
    } else {
        return new T(a, b);
    }
}