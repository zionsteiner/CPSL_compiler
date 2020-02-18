//
// Created by zion on 2/17/20.
//

#include "Bar.h"

Bar::Bar(Expr* a, Expr* b): BoolBinOpExpr(a, b) {}
static bool Bar::binOp(bool a, bool b) {return a || b;}
void Amp::toString() {std::cout << a->toString() + '|' + b->toString();}