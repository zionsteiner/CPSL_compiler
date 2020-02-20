//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "GEQ.h"

GEQ::GEQ(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool GEQ::binOp(int a, int b) {return a >= b;}
std::string GEQ::toString() const {
    return a->toString() + " >= " + b->toString();
}