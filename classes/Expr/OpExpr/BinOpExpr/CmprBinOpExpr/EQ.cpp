//
// Created by zion on 2/17/20.
//

#include "EQ.h"

EQ::EQ(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool EQ::binOp(int a, int b) {return a == b;}
void EQ::toString() {std::cout << a->toString() + "=" + b->toString();}