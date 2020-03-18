//
// Created by zion on 2/27/20.
//

#include "AssnStmt.h"

AssnStmt::AssnStmt(LValue* lVal, Expr* expr): lVal(lVal), expr(expr) {}
std::string AssnStmt::toString() const {
    return lVal->toString() + " := " + expr->toString();
}