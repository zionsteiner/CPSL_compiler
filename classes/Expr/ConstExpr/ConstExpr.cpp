//
// Created by zion on 2/10/20.
//

#include "ConstExpr.h"

ConstExpr::ConstExpr(TypeEnum t): Expr(t) {}
bool ConstExpr::isCompVal() {return true;}
