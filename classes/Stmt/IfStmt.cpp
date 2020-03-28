//
// Created by zion on 2/27/20.
//

#include "IfStmt.h"

IfStmt::IfStmt(Expr* condition, std::vector<Stmt*>* stmts, std::vector<ElseIfStmt*>* elseIfStmts, ElseStmt* elseStmt):
        condition(condition), stmts(stmts), elseIfStmts(elseIfStmts), elseStmt(elseStmt) {}

std::string IfStmt::toString() const {
    std::string elseIfStmtsStr;
    if (elseIfStmts != nullptr) {
        for (auto elseIfStmt = elseIfStmts->begin(); elseIfStmt != elseIfStmts->end(); ++elseIfStmt) {
            elseIfStmtsStr += (*elseIfStmt)->toString();
        }
    } else {
        elseIfStmtsStr = "";
    }

    std::string elseStmtStr;
    if (elseStmt != nullptr) {
        elseStmtStr = ' ' + elseStmt->toString();
    } else {
        elseStmtStr = "";
    }

    std::string retStr = "if " + condition->toString() + " then";
    for (auto stmt = stmts->begin(); stmt != stmts->end(); ++stmt) {
        retStr += ' ' + (*stmt)->toString();
    }
    retStr += ' ' + elseIfStmtsStr + ' ' + elseStmtStr;
}