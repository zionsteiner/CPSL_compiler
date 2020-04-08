//
// Created by zion on 2/23/20.
//

#include <classes/Expr/ConstExpr/IntConstExpr.h>
#include "OrdFunc.h"
#include "../../../ConstExpr/ChrConstExpr.h"

OrdFunc::OrdFunc(Expr* expr): UnaryOpExpr(expr, INT_T) {}
Expr* OrdFunc::op(Expr* a) {
    if (a->isCompVal()) {
        auto a_new = dynamic_cast<ChrConstExpr*>(a);
        auto val = OrdFunc::op(a_new->value);
        delete a_new;

        return new IntConstExpr(val);
    } else {
        return new OrdFunc(a);
    }
}

int OrdFunc::op(char a) {
    int a_int = (int)a;
    return a_int;
}

std::string OrdFunc::toString() const {
    return "ord(" + expr->toString() + ')';
}

RegisterPool::Register OrdFunc::emitMips() {
    return expr->emitMips();
}