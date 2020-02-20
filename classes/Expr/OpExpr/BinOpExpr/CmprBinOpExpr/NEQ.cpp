//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "NEQ.h"

NEQ::NEQ(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool NEQ::binOp(int a, int b) {return a != b;}
std::string NEQ::toString() const {
    return a->toString() + " <> " + b->toString();
}
