//
// Created by zion on 2/23/20.
//

#include <Expr/Const/IntConst.h>
#include <Expr/Const/BoolConst.h>
#include "SuccFunc.h"

SuccFunc::SuccFunc(Expr* a): UnaryOpExpr(a) {}
Expr* SuccFunc::op(BoolConst* a) {
    auto val = SuccFunc::op(a->value);
    delete a;

    return new BoolConst(val);
}
Expr* SuccFunc::op(IntConst* a) {
    auto val = SuccFunc::op(a->value);
    delete a;

    return new IntConst(val);
}

bool SuccFunc::op(bool a) {
    return !a;
}

int SuccFunc::op(int a) {
    return ++a;
}

std::string SuccFunc::toString() const {
    return "succ(" + a->toString() + ')';
}