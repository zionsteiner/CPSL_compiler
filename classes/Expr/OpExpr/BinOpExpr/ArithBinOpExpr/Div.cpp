//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "Div.h"

Div::Div(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}
int Div::binOp(int a, int b) {
    if (b == 0) {
        throw "Cannot divide by zero";
    } else {
        return a / b;
    }
}

std::string Div::toString() const {
    return "(" + a->toString() + " / " + b->toString() + ")";
}