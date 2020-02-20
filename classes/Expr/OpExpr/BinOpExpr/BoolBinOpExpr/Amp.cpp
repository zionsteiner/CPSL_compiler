//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>
#include "Amp.h"
#include "BoolBinOpExpr.h"

Amp::Amp(Expr* a, Expr* b): BoolBinOpExpr(a, b) {}
bool Amp::binOp(int a, int b) {return a && b;}
std::string Amp::toString() const {
    return a->toString() + " & " + b->toString();
}