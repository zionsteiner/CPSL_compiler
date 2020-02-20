//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "GT.h"

GT::GT(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool GT::binOp(int a, int b) {return a > b;}
std::string GT::toString() const {
    return a->toString() + " > " + b->toString();
}