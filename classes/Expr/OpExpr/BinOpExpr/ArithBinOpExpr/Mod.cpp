//
// Created by zion on 2/17/20.
//

#include "Mod.h"

Mod::Mod(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}
static int Mod::binOp(int a, int b) {return a % b;}
void Mod::toString() {std::cout << a->toString() + '%' + b->toString()}