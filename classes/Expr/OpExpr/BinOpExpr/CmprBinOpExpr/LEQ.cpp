//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "LEQ.h"

LEQ::LEQ(Expr* a, Expr* b): CmprBinOpExpr(a, b) {}
bool LEQ::binOp(int, int) {return a <= b;}
std::string LEQ::toString() const {
    return a->toString() + " <= " + b->toString();
}
