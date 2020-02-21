//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "Mod.h"

Mod::Mod(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}
int Mod::binOp(int a, int b) {return a % b;}

std::string Mod::toString() const {
    return a->toString() + " % " + b->toString();
}