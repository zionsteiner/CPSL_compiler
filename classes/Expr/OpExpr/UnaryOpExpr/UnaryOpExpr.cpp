//
// Created by zion on 2/23/20.
//

#include "UnaryOpExpr.h"

UnaryOpExpr::UnaryOpExpr(Expr* expr): expr(expr) {}
UnaryOpExpr::UnaryOpExpr(Expr* expr, TypeEnum t): Expr(t), expr(expr) {}
bool UnaryOpExpr::isCompVal() {
    return false;
}
