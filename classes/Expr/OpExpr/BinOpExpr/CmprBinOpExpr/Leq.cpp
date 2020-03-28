//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "Leq.h"

Leq::Leq(Expr* expr1, Expr* expr2): CmprBinOpExpr(expr1, expr2) {}
bool Leq::binOp(int a, int b) {return a <= b;}
std::string Leq::toString() const {
    return a->toString() + " <= " + b->toString();
}
