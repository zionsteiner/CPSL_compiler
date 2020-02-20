//
// Created by zion on 2/17/20.
//

#include <sstream>
#include "Bar.h"
#include "Amp.h"

Bar::Bar(Expr* a, Expr* b): BoolBinOpExpr(a, b) {}
bool Bar::binOp(bool a, bool b) {return a || b;}
std::string Bar::toString() const {
    return a->toString() + " | " + b->toString();
}