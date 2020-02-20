//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "Sub.h"

Sub::Sub(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}
static int Sub::binOp(int a, int b) {return a - b;}
std::string Sub::toString() const {
    return a->toString() + " - " + b->toString();
}