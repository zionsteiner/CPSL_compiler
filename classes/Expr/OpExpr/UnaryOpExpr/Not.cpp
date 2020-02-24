//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>

#include "Not.h"
#include "../../Const/BoolConst.h"

Not::Not(Expr* a): UnaryOpExpr(a) {}
Expr* Not::op(Expr* a) {
    if (a->isCompVal()) {
        auto a = dynamic_cast<BoolConst*> (a);
        auto val = Not::op(a->value);
        delete a;

        return new BoolConst(val);
    } else {
        return new Not(a);
    }
}
bool Not::op(bool a) {return !a;}
std::string Not::toString() const {
    return '~' + a->toString();
}