//
// Created by zion on 2/23/20.
//

#include "UnaryOpExpr.h"

UnaryOpExpr::UnaryOpExpr(Expr* a): a(a) {}
bool UnaryOpExpr::isCompVal() {
    return false;
}
