//
// Created by zion on 2/17/20.
//

#include "LT.h"

LT::LT(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool LT::binOp(int a, int b) {return a < b;}
void LT::toString() {std::cout << a->toString() + '<' + b->toString();}
