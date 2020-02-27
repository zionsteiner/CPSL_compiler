//
// Created by zion on 2/26/20.
//

#include "ElseIfStmt.h"

ElseIfStmt::ElseIfStmt(Expr* expr, StmtList* stmts): expr(expr), stmts(stmts) {}
std::string ElseIfStmt::toString() const {
    return "elseif " + expr->toString() + " then" + stmts->toString();
}