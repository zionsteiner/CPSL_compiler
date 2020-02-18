//
// Created by zion on 2/17/20.
//

#include "Div.h"

Div::Div(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}
static int Div::binOp(int a, int b) {
    if (b == 0) {
        throw "Cannot divide by zero";
    } else {
        return a / b;
    }
}
void Div::toString() {std::cout << a->toString() + '/' + b->toString();}