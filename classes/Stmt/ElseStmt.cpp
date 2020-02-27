//
// Created by zion on 2/26/20.
//

#include "ElseStmt.h"

ElseStmt::ElseStmt(StmtList* stmts): stmts(stmts) {}
std::string ElseStmt::toString() const {
    return "else " + stmts->toString();
}