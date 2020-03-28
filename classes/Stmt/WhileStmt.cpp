//
// Created by zion on 2/26/20.
//

#include "WhileStmt.h"

WhileStmt::WhileStmt(Expr* expr, std::vector<Stmt*>* stmts): expr(expr), stmts(stmts) {}
std::string WhileStmt::toString() const {
    std::string retStr = "while " + expr->toString() + " do";
    for (auto stmt = stmts->begin(); stmt != stmts->end(); ++stmt) {
        retStr += ' ' + (*stmt)->toString();
    }
    retStr += " end";
    return retStr;
}