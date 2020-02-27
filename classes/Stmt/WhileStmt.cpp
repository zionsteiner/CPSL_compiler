//
// Created by zion on 2/26/20.
//

#include "WhileStmt.h"

WhileStmt::WhileStmt(Expr* expr, StmtList* stmts): expr(expr), stmts(stmts) {}
std::string WhileStmt::toString() const {
    return "while " + expr->toString() + " do" + stmts->toString() + " end";
}