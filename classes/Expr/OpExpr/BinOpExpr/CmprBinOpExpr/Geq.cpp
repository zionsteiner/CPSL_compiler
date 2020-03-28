//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "Geq.h"

Geq::Geq(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool Geq::binOp(int a, int b) {return a >= b;}
std::string Geq::toString() const {
    return a->toString() + " >= " + b->toString();
}