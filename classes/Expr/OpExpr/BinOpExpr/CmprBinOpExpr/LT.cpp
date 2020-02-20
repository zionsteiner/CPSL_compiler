//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "LT.h"

LT::LT(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool LT::binOp(int a, int b) {return a < b;}
std::string LT::toString() const {
    return a->toString() + " < " + b->toString();
}
