//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>

#include "Not.h"

Not::Not(Expr* expr): UnaryOpExpr(expr) {}
Expr* Not::op(Expr* a) {
    if (a->isCompVal()) {
        auto a_new = dynamic_cast<BoolConstExpr*> (a);
        auto val = Not::op(a_new->value);
        delete a_new;

        return new BoolConstExpr(val);
    } else {
        return new Not(a);
    }
}
bool Not::op(bool a) {return !a;}
std::string Not::toString() const {
    return '~' + expr->toString();
}