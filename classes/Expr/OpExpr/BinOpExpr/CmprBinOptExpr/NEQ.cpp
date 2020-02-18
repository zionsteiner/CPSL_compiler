//
// Created by zion on 2/17/20.
//

#include "NEQ.h"

NEQ::NEQ(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool NEQ::binOp(int a, int b) {return a != b;}
void NEQ::toString() {std::cout << a->toString() + "<>" + b->toString();}
