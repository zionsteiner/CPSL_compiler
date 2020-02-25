//
// Created by zion on 2/24/20.
//

#include "ReturnStmt.h"

ReturnStmt::ReturnStmt(Expr* expr): expr(expr) {}
std::string ReturnStmt::toString() const {
    if (expr == nullptr) {
        return "return"
    } else {
        return "return " + expr->toString();
    }
}