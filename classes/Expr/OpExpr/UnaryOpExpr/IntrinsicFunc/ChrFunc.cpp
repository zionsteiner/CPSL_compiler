//
// Created by zion on 2/23/20.
//

#include "ChrFunc.h"
#include "../../../ConstExpr/IntConstExpr.h"
#include "../../../ConstExpr/ChrConstExpr.h"

ChrFunc::ChrFunc(Expr* expr): UnaryOpExpr(expr, CHR_T) {}

Expr* ChrFunc::op(Expr* a) {
    if (a->isCompVal()) {
        auto a_new = dynamic_cast<IntConstExpr*> (a);
        auto val = ChrFunc::op(a_new->value);
        delete a_new;

        return new ChrConstExpr(val);
    } else {
        return new ChrFunc(a);
    }
}

char ChrFunc::op(int a) {
    char a_new = a;
    return a_new;
}

std::string ChrFunc::toString() const {
    return "chr(" + expr->toString() + ')';
}

RegisterPool::Register ChrFunc::emitMips() {
    return expr->emitMips();
}
