//
// Created by zion on 2/27/20.
//

#include <iostream>
#include <globals.h>
#include "IfStmt.h"

IfStmt::IfStmt(Expr* condition, std::vector<Stmt*>* stmts, std::vector<ElseIfStmt*>* elseIfStmts, ElseStmt* elseStmt):
        condition(condition), stmts(stmts), elseIfStmts(elseIfStmts), elseStmt(elseStmt) {}

std::string IfStmt::toString() const {
    std::string elseIfStmtsStr;
    if (elseIfStmts != nullptr) {
        for (auto elseIfStmt = elseIfStmts->begin(); elseIfStmt != elseIfStmts->end(); ++elseIfStmt) {
            elseIfStmtsStr += "\n" + (*elseIfStmt)->toString() + ";";
        }
    } else {
        elseIfStmtsStr = "";
    }

    std::string elseStmtStr;
    if (elseStmt != nullptr) {
        elseStmtStr = "\n" + elseStmt->toString() + ";";
    } else {
        elseStmtStr = "";
    }

    std::string retStr = "if (" + condition->toString() + ")" + " then";
    for (auto stmt = stmts->begin(); stmt != stmts->end(); ++stmt) {
        retStr += "\n\t" + (*stmt)->toString() + ";";
    }
    retStr += elseIfStmtsStr + elseStmtStr + " end;";

    return retStr;
}

void IfStmt::emitMips() {
    std::cout << "# If" << std::endl;
    std::string thenLabel = symbolTable.getNextLabel();
    std::string nextLabel = symbolTable.getNextLabel();
    std::vector<std::string> elseIfLabels;
    std::vector<std::string> thenLabels;

    if (elseIfStmts != nullptr) {
        for (auto elseIf: *elseIfStmts) {
            elseIfLabels.push_back(symbolTable.getNextLabel()); // add a label for each elseIfStmt
            thenLabels.push_back(symbolTable.getNextLabel());   // add a label for each elseIf body
        }
    }
    if (elseStmt != nullptr) {
        elseIfLabels.push_back(symbolTable.getNextLabel()); // add a label for elseStmt
    }

    // Check initial condition
    auto conditionReg = condition->emitMips();
    auto testReg = registerPool.get();
    std::cout << "li " + testReg.getRegId() + ", 1" << std::endl;
    std::cout << "beq " + conditionReg.getRegId() + ", " + testReg.getRegId() + ", " + thenLabel << std::endl;

    if (elseIfStmts != nullptr || elseStmt != nullptr) {
        std::cout << "j " + elseIfLabels[0] << std::endl;
    } else {
        std::cout << "j " + nextLabel << std::endl;
    }

    // Then stmts
    std::cout << thenLabel + ":" << std::endl;
    for (auto stmt: *stmts) {
        stmt->emitMips();
    }
    std::cout << "j " + nextLabel << std::endl;

    // ElseIfs
    if (elseIfStmts != nullptr) {
        for (int i = 0; i < elseIfStmts->size(); ++i) {
            std::cout << elseIfLabels[i] + ":" << std::endl;

            auto elseIf = (*elseIfStmts)[i];
            auto expr = elseIf->expr;
            auto exprReg = expr->emitMips();

            // Eval condition
            std::cout << "li " + testReg.getRegId() + ", 1" << std::endl;
            std::cout << "beq " + exprReg.getRegId() + ", " + testReg.getRegId() + ", " + thenLabels[i] << std::endl;
            std::cout << "j " + elseIfLabels[i + 1] << std::endl;

            // Then
            std::cout << thenLabels[i] + ":" << std::endl;
            stmts = (*elseIfStmts)[i]->stmts;
            for (auto stmt: *(*elseIfStmts)[i]->stmts) {
                stmt->emitMips();
            }
            std::cout << "j " + nextLabel << std::endl;
        }
    }
    // Else
    if (elseStmt != nullptr) {
        int vecSize = elseIfLabels.size();
        std::cout << elseIfLabels[vecSize - 1] + ":" << std::endl;
        for (auto stmt: *elseStmt->stmts) {
            stmt->emitMips();
        }
        std::cout << "j " + nextLabel << std::endl;
    }

    // Next
    std::cout << nextLabel + ":" << std::endl;
}
