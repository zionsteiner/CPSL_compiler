//
// Created by zion on 2/26/20.
//

#include "RepeatStmt.h"

RepeatStmt::RepeatStmt(std::vector<Stmt*>* stmts, Expr* expr): stmts(stmts), expr(expr) {}

std::string RepeatStmt::toString() const {
    std::string retStr = "repeat";
    for (auto stmt = stmts->begin(); stmt != stmts->end(); ++stmt) {
        retStr += ' ' + (*stmt)->toString();
    }
    retStr += " until" + expr->toString();
    return retStr;
}