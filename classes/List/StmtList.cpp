//
// Created by zion on 2/26/20.
//

#include "StmtList.h"

StmtList::StmtList(Stmt* stmt) {
    list.push_back(stmt);
}

void StmtList::append(Stmt* stmt) {
    list.push_back(stmt);
}

std::string StmtList::toString() const {
    std::string retStr = list[0]->toString();
    if (list.size() > 1) {
        for (auto stmt = list.begin() + 1; stmt != list.end(); ++stmt) {
            retStr += ", " + (*stmt)->toString();
        }
    }

    return retStr;
}