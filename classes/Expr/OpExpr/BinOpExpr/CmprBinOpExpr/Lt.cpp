//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "Lt.h"

Lt::Lt(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool Lt::binOp(int a, int b) {return a < b;}
std::string Lt::toString() const {
    return a->toString() + " < " + b->toString();
}
