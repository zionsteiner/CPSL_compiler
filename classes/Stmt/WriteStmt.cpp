//
// Created by zion on 2/24/20.
//

#include <Expr/Expr.h>
#include "WriteStmt.h"

WriteStmt::WriteStmt(ExprList<Expr*> *args) : args(args) {}
std::string WriteStmt::toString() const {
    return "write (" + args->toString() + ')';
}