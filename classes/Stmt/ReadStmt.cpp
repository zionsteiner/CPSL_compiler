//
// Created by zion on 2/24/20.
//

#include "../Expr/LValue/LValue.h"
#include "ReadStmt.h"

ReadStmt::ReadStmt(std::vector<LValue*>* lValList): lValList(lValList) {}
std::string ReadStmt::toString() const {
    std::string retStr = "read (";
    for (auto lVal = lValList->begin(); lVal != lValList->end(); ++lVal) {
        retStr += ' ' + (*lVal)->toString();
    }
    retStr += ')';
    return retStr;
}