//
// Created by zion on 2/24/20.
//

#include <iostream>
#include <globals.h>
#include "../Expr/LValue/LValue.h"
#include "ReadStmt.h"

ReadStmt::ReadStmt(std::vector<LValue*>* lValList): lValList(lValList) {}
std::string ReadStmt::toString() const {
    std::string retStr = "read(" + (*lValList)[0]->toString();
    for (auto lVal = lValList->begin()+1; lVal != lValList->end(); ++lVal) {
        retStr += ", " + (*lVal)->toString();
    }
    retStr += ')';
    return retStr;
}

void ReadStmt::emitMips() {
    for (auto lVal = lValList->begin(); lVal != lValList->end(); ++lVal) {
        auto symbol = (*lVal)->getSymbol();
        int offset = symbol->offset;

        if (offset == -1) {
            throw std::invalid_argument("ERROR: attempt to read value to an invalid ID");
        }

        auto type = symbol->type->typeEnum;
        if (type == INT_T) {
            std::cout << "# Int Read" << std::endl;
            std::cout << "li $v0, 5" << std::endl;
            std::cout << "syscall" << std::endl;
            std::cout << "sw $v0, " + std::to_string(offset) + "(" + symbolTable.getBaseReg() + ")" << std::endl;
        } else if (type == CHR_T) {
            std::cout << "# Chr Read" << std::endl;
            std::cout << "li $v0, 12" << std::endl;
            std::cout << "syscall" << std::endl;
            std::cout << "sw $v0, " + std::to_string(offset) + "(" + symbolTable.getBaseReg() + ")" << std::endl;
        } else {
            throw std::invalid_argument("ERROR: Only int and chr types can be read through the READ stmt");
        }
    }
}
