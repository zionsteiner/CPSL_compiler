//
// Created by zion on 2/28/20.
//

#include <iostream>
#include "Block.h"

Block::Block(std::vector<Stmt*>* stmts): stmts(stmts) {}
std::string Block::toString() const {
    std::string retStr = "BEGIN";
    retStr += "\n\t" + (*stmts)[0]->toString();

    if (stmts->size() > 1) {
        for (auto stmt = stmts->begin() + 1; stmt != stmts->end(); ++stmt) {
            retStr += ";\n\t" + (*stmt)->toString();
        }
    }
    retStr += "\nEND";

    return retStr;
}

void Block::emitMips() {
    for (auto stmt = stmts->begin(); stmt != stmts->end(); ++stmt) {
        (*stmt)->emitMips();
    }
}