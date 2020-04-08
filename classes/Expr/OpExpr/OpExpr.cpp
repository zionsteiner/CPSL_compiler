//
// Created by zion on 2/17/20.
//

#include "OpExpr.h"

OpExpr::OpExpr(TypeEnum t): Expr(t) {}
bool OpExpr::isCompVal() {return false;}
