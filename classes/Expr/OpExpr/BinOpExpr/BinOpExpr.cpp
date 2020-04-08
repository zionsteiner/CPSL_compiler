//
// Created by zion on 2/17/20.
//

#include "BinOpExpr.h"

BinOpExpr::BinOpExpr(Expr* a, Expr* b, TypeEnum t): OpExpr(t), a(a), b(b) {}
BinOpExpr::~BinOpExpr() {delete a; delete b;}