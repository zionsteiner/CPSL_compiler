//
// Created by zion on 2/27/20.
//

#include "IfStmt.h"

IfStmt::IfStmt(Expr* condition, StmtList* stmts, ElseIfStmtList* elseIfStmts, ElseStmt* elseStmt):
        condition(condition), stmts(stmts), elseIfStmts(elseIfStmts), elseStmt(elseStmt) {}

std::string IfStmt::toString() const {
    std::string elseIfStmtsStr;
    if (elseIfStmts != nullptr) {
        elseIfStmtsStr = ' ' + elseIfStmts->toString();
    } else {
        elseIfStmtsStr = "";
    }

    std::string elseStmtStr;
    if (elseStmt != nullptr) {
        elseStmtStr = ' ' + elseStmt->toString();
    } else {
        elseStmtStr = "";
    }

    return "if " + condition->toString() + " then" + stmts->toString() + elseIfStmtsStr + elseStmtStr;
}