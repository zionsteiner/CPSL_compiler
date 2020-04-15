//
// Created by zion on 2/26/20.
//

#include <globals.h>
#include <iostream>
#include "RepeatStmt.h"

RepeatStmt::RepeatStmt(std::vector<Stmt*>* stmts, Expr* expr): stmts(stmts), expr(expr) {}

std::string RepeatStmt::toString() const {
    std::string retStr = "repeat\n";
    for (auto stmt = stmts->begin(); stmt != stmts->end(); ++stmt) {
        retStr += ' ' + (*stmt)->toString();
    }
    retStr += " until " + expr->toString();
    return retStr;
}

void RepeatStmt::emitMips() {
    std::string label = symbolTable.getLabel();

    std::cout << label + ":" << std::endl;
    for (auto stmt: *stmts) {
        stmt->emitMips();
    }
    auto exprReg = expr->emitMips();
    std::cout << "beq " + exprReg.getRegId() + ", $zero, " + label << std::endl;
}
