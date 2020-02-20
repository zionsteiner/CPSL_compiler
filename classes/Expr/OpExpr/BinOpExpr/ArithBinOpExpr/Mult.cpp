//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "Mult.h"

Mult::Mult(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}
static int Mult::binOp(int a, int b) {return a * b;}

std::string Mult::toString() const {
    return a->toString() + " * " + b->toString();
}
