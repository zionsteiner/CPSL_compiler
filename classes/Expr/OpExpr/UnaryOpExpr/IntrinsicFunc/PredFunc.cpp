//
// Created by zion on 2/23/20.
//

#include <Expr/Const/IntConst.h>
#include <Expr/Const/BoolConst.h>
#include "PredFunc.h"

PredFunc::PredFunc(Expr* a): UnaryOpExpr(a) {}
Expr* PredFunc::op(BoolConst* a) {
    auto val = PredFunc::op(a->value);
    delete a;

    return new BoolConst(val);
}
Expr* PredFunc::op(IntConst* a) {
    auto val = PredFunc::op(a->value);
    delete a;

    return new IntConst(val);
}

bool PredFunc::op(bool a) {
    return !a;
}

int PredFunc::op(int a) {
    return --a;
}

std::string PredFunc::toString() const {
    return "pred(" + a->toString() + ')';
}