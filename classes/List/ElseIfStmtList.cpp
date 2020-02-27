//
// Created by zion on 2/27/20.
//

#include "ElseIfStmtList.h"

ElseIfStmtList::ElseIfStmtList(ElseIfStmt* stmt) {
    list.push_back(stmt);
}

void ElseIfStmtList::append(ElseIfStmt* stmt) {
    list.push_back(stmt);
}

std::string ElseIfStmtList::toString() const {
    std::string retStr;
    for (auto stmt = list.begin(); stmt != list.end(); ++stmt) {
        retStr += (*stmt)->toString();
    }

    return retStr;
}