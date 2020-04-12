//
// Created by zion on 2/23/20.
//


#include "SuccFunc.h"

SuccFunc::SuccFunc(Expr* expr): UnaryOpExpr(expr) {
    if (expr->typeEnum == INT_T) {
        this->typeEnum = INT_T;
    } else if (expr->typeEnum == BOOL_T) {
        this->typeEnum = BOOL_T;
    } else {
        throw "Error in PredFunc: expected either int or bool";
    }
}

Expr* SuccFunc::op(Expr* expr) {
    auto expr_new = dynamic_cast<BoolConstExpr*>(expr);
    if (expr_new == nullptr) {
        auto expr_new = dynamic_cast<IntConstExpr*>(expr);
        if (expr_new == nullptr) {
             throw std::invalid_argument("Argument must be of type 'BoolConstExpr' or 'IntConstExpr'");
        } else {
            auto val = SuccFunc::op(expr_new->value);

            return new IntConstExpr(val);
        }
    } else {
        auto val = SuccFunc::op(expr_new->value);

        return new BoolConstExpr(val);
    }
}

bool SuccFunc::op(bool a) {
    return !a;
}

int SuccFunc::op(int a) {
    return ++a;
}

std::string SuccFunc::toString() const {
    return "succ(" + expr->toString() + ')';
}