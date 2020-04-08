//
// Created by zion on 2/28/20.
//

#include <stdexcept>
#include "ConstAssign.h"

ConstAssign::ConstAssign(Ident* id, Expr* expr): id(id), expr(expr) {
    if (!expr->isCompVal()) {
        throw std::invalid_argument("ERROR: Non-compile value used in CONST assignment");
    }
}
std::string ConstAssign::toString() const {
    return  id->toString() + " = " + expr->toString() + ';';
}