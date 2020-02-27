//
// Created by zion on 2/26/20.
//

#include "RepeatStmt.h"

RepeatStmt::RepeatStmt(StmtList* stmts, Expr* expr): stmts(stmts), expr(expr) {}

std::string RepeatStmt::toString() const {
    return "repeat " + stmts->toString() + "until" + expr->toString();
}