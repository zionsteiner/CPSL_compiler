//
// Created by zion on 2/28/20.
//

#include "ConstAssign.h"

ConstAssign::ConstAssign(Ident* id, Expr* expr): id(id), expr(expr) {
    if (!expr->isCompVal()) {
        throw "ERROR: Non-compile value used in CONST assignment";
    }
}
std::string ConstAssign::toString() const {
    return  id->toString() + " = " + expr->toString() + ';';
}