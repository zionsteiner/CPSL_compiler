//
// Created by zion on 2/26/20.
//

#include <globals.h>
#include <iostream>
#include "../Expr/Ident.h"
#include "ForStmt.h"

ForStmt::ForStmt(Ident* id, Expr* from, bool incrUp, Expr* to, std::vector<Stmt*>* stmts):
    id(id), from(from), incrUp(incrUp), to(to), stmts(stmts) {}

std::string ForStmt::toString() const {
    std::string iterDirection;
    if (incrUp) {
        iterDirection = "to";
    } else {
        iterDirection = "downto";
    }

    std::string retStr = "for " + id->toString() + " := " + from->toString() + " " + iterDirection + " " + to->toString() + " do" + "\n";
    for (auto stmt = stmts->begin(); stmt != stmts->end(); ++stmt) {
        retStr += "\t" + (*stmt)->toString() + "\n";
    }
    retStr += " end";
    return retStr;
}

void ForStmt::emitMips() {
    // Init
    std::string testLabel = symbolTable.getNextLabel();
    std::string bodyLabel = symbolTable.getNextLabel();
    std::string nextLabel = symbolTable.getNextLabel();

    int offset = symbolTable.getNextOffset();
    Type* type = symbolTable.lookupType("integer");
    std::string base = symbolTable.getCurrBaseReg();
    auto fromReg = from->emitMips();
    std::cout << "sw " + fromReg.getRegId() + ", " + std::to_string(offset) + "(" + base + ")" << std::endl;
    Symbol* fromSymbol = new Symbol(offset, type);
    symbolTable.addSymbol(id->id, fromSymbol);

    auto toReg = to->emitMips();

    std::cout << "# For loop" << std::endl;

    // Test
    auto testReg = registerPool.get();
    std::cout << testLabel + ":" << std::endl;
    std::cout << "lw " + fromReg.getRegId() + ", " + std::to_string(offset) + "(" + base + ")" << std::endl;
    if (incrUp) {
        std::cout << "sle " + testReg.getRegId() + ", " + fromReg.getRegId() + ", " + toReg.getRegId() << std::endl;
        std::cout << "beq " + testReg.getRegId() + ", $zero, " + nextLabel << std::endl;
    } else {
        std::cout << "sge " + testReg.getRegId() + ", " + fromReg.getRegId() + ", " + toReg.getRegId() << std::endl;
        std::cout << "beq " + testReg.getRegId() + ", $zero, " + nextLabel << std::endl;
    }
    std::cout << "j " + bodyLabel << std::endl;

    // Body
    std::cout << bodyLabel + ":" << std::endl;
    for (auto stmt: *stmts) {
        stmt->emitMips();
    }

    // Update
    std::cout << "lw " + fromReg.getRegId() + ", " + std::to_string(offset) + "(" + base + ")" << std::endl;
    if (incrUp) {
        std::cout << "addi " + fromReg.getRegId() + ", " + fromReg.getRegId() + ", 1" << std::endl;
        std::cout << "sw " + fromReg.getRegId() + ", " + std::to_string(offset) + "(" + base + ")" << std::endl;
    } else {
        std::cout << "subi " + fromReg.getRegId() + ", " + fromReg.getRegId() + ", 1" << std::endl;
        std::cout << "sw " + fromReg.getRegId() + ", " + std::to_string(offset) + "(" + base + ")" << std::endl;
    }
    std::cout << "j " + testLabel << std::endl;

    // Next
    symbolTable.removeSymbol(id->id);
    std::cout << nextLabel + ":" << std::endl;
}
