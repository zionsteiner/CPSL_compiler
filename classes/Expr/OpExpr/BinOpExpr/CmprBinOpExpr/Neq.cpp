//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "Neq.h"

Neq::Neq(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool Neq::binOp(int a, int b) {return a != b;}
std::string Neq::toString() const {
    return a->toString() + " <> " + b->toString();
}
