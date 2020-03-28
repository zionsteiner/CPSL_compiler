//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "Eq.h"

Eq::Eq(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool Eq::binOp(int a, int b) {return a == b;}
std::string Eq::toString() const {
    return a->toString() + " + " + b->toString();;
}
