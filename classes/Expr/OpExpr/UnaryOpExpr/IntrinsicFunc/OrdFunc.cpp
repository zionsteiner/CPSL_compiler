//
// Created by zion on 2/23/20.
//

#include "OrdFunc.h"
#include "../../../Const/ChrConst.h"

OrdFunc::OrdFunc(Expr* a): UnaryOpExpr(a) {}
Expr * OrdFunc::op(Expr* a) {
    if (a->isCompVal()) {
        auto a = dynamic_cast<ChrConst*> (a);
        auto val = OrdFunc::op(a->value);
        delete a

        return new OrdFunc(val);
    } else {
        return new OrdFunc(a);
    }
}

int OrdFunc::op(char a) {
    int a = (int)a;
    return a;
}

std::string OrdFunc::toString() const {
    return "ord(" + a->toString() + ')';
}