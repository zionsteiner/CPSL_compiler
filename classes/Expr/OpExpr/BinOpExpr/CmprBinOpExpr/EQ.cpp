//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "EQ.h"

EQ::EQ(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool EQ::binOp(int a, int b) {return a == b;}
std::string EQ::toString() const {
    return a->toString() + " + " + b->toString();;
}