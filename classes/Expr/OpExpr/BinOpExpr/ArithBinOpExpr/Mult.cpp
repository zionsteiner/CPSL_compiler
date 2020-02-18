//
// Created by zion on 2/17/20.
//

#include "Mult.h"

Mult::Mult(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}
static int Mult::binOp(int a, int b) {return a * b;}
void Mult::toString() {std::cout << a->toString() + '*' + b->toString();}
