//
// Created by zion on 2/17/20.
//

#include "LEQ.h"

LEQ::LEQ(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool LEQ::binOp(int, int) {return a <= b;}
void LEQ::toString() {std::cout << a->toString() + "<=" + b->toString();}
