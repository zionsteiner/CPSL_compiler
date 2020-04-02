//
// Created by zion on 2/14/20.
//

#include <iostream>
#include <sstream>
#include "Add.h"

Add::Add(Expr* a, Expr* b): ArithBinOpExpr(a, b) {}
int Add::binOp(int a, int b) {return a + b;}
std::string Add::toString() const {
    return "(" + a->toString() + " + " + b->toString() + ")";
}
