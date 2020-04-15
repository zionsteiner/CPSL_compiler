//
// Created by zion on 2/26/20.
//

#include "ElseIfStmt.h"

ElseIfStmt::ElseIfStmt(Expr* expr, std::vector<Stmt*>* stmts): expr(expr), stmts(stmts) {}
std::string ElseIfStmt::toString() const {
    std::string retStr = "elseif (" + expr->toString() + ")" + " then";
    for (auto stmt = stmts->begin(); stmt != stmts->end(); ++stmt) {
        retStr += "\n\t" + (*stmt)->toString();
    }
    return retStr;
}