//
// Created by zion on 2/23/20.
//

#include <Expr/Const/ChrConst.h>
#include "ChrFunc.h"
#include "../../../Const/IntConst.h"

ChrFunc::ChrFunc(Expr* a): UnaryOpExpr(a) {}

Expr* ChrFunc::op(Expr* a) {
    if (a->isCompVal()) {
        auto a = dynamic_cast<IntConst*> (a);
        auto val = ChrFunc::op(a->value);
        delete a;

        return new ChrConst(val);
    } else {
        return new ChrFunc(a);
    }
}

char ChrFunc::op(int a) {
    char a = a;
    return a;
}

std::string ChrFunc::toString() const {
    return "chr(" + a->toString() + ')';
}
