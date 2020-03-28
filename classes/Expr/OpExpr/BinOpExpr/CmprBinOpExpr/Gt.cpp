//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "Gt.h"

Gt::Gt(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool Gt::binOp(int a, int b) {return a > b;}
std::string Gt::toString() const {
    return a->toString() + " > " + b->toString();
}