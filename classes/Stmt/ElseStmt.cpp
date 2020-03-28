//
// Created by zion on 2/26/20.
//

#include "ElseStmt.h"

ElseStmt::ElseStmt(std::vector<Stmt*>* stmts): stmts(stmts) {}
std::string ElseStmt::toString() const {
    std::string retStr = "else";
    for (auto stmt = stmts->begin(); stmt != stmts->end(); ++stmt) {
        retStr += ' ' + (*stmt)->toString();
    }
    return retStr;
}