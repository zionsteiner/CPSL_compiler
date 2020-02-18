//
// Created by zion on 2/14/20.
//

#include "Add.h"

Add::Add(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}
static int Add::binOp(int a, int b) {return a + b;}
void Add::toString() {std::cout << a->toString() + '+' + b->toString();}
