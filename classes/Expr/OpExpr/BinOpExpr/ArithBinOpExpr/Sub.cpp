//
// Created by zion on 2/17/20.
//

#include "Sub.h"

Sub::Sub(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}
static int Sub::binOp(int a, int b) {return a - b;}
void Sub::toString() {std::cout << a->toString() + '-' + b->toString();}