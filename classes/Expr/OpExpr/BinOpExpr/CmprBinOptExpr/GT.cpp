//
// Created by zion on 2/17/20.
//

#include "GT.h"

GT::GT(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool GT::binOp(int a, int b) {return a > b;}
void GT::toString() {std::cout << a->toString() + '>' + b->toString();}