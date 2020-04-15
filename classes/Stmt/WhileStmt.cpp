//
// Created by zion on 2/26/20.
//

#include <iostream>
#include <globals.h>
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

void WhileStmt::emitMips() {
    std::cout << "# While stmt" << std::endl;
    std::string testLabel = symbolTable.getNextLabel();
    std::string bodyLabel = symbolTable.getNextLabel();
    std::string nextLabel = symbolTable.getNextLabel();

    // Test condition
    std::cout << testLabel + ":" << std::endl;
    auto exprReg = expr->emitMips();
    auto tempReg = registerPool.get();
    std::cout << "li " + tempReg.getRegId() + ", 1" << std::endl;
    std::cout << "beq " + exprReg.getRegId() + ", " + tempReg.getRegId() + ", " + bodyLabel << std::endl;
    std::cout << "j " + nextLabel << std::endl;

    // Stmt body
    std::cout << bodyLabel + ":" << std::endl;
    for (auto stmt: *stmts) {
        stmt->emitMips();
    }
    std::cout << "j " + testLabel << std::endl;

    // Next
    std::cout << nextLabel + ":" << std::endl;
}