//
// Created by zion on 2/17/20.
//

#include "GEQ.h"

GEQ::GEQ(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool GEQ::binOp(int a, int b) {return a >= b;}
void GEQ::toString() {std::cout << a->toString() + ">=" + b->toString();}