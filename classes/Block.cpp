//
// Created by zion on 2/28/20.
//

#include "Block.h"

Block::Block(std::vector<Stmt*>* stmts): stmts(stmts) {}
int Block::toString() const {
    std::string retStr = "begin ";
    retStr += (*stmts)[0];

    if (stmts->size() > 1) {
        for (auto stmt = stmts.begin() + 1; stmt != stmts.end(); ++stmt) {
            retStr += "; " + (*stmt)->toString();
        }
        retStr += " end";
    }

    return retStr;
}