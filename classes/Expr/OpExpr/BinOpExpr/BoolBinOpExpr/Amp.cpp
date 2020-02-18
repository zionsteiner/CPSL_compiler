//
// Created by zion on 2/17/20.
//

#include "Amp.h"

Amp::Amp(Expr* a, Expr* b): BoolBinOpExpr(a, b) {}
static bool Amp::binOp(bool a, bool b) {return a && b;}
void Amp::toString() {std::cout << a->toString() + '&' + b->toString();}