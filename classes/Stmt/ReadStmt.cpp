//
// Created by zion on 2/24/20.
//

#include <Expr/LValue/LValue.h>
#include "ReadStmt.h"

ReadStmt::ReadStmt(ExprList<LValue*>* lValList): lValList(lValList) {}
std::string ReadStmt::toString() const {
    return "read (" + lValList->toString() + ')';
}