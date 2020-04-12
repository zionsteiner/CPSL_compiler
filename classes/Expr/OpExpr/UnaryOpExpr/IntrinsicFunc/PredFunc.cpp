//
// Created by zion on 2/23/20.
//

#include <stdexcept>
#include "PredFunc.h"

PredFunc::PredFunc(Expr* expr): UnaryOpExpr(expr) {
    if (expr->typeEnum == INT_T) {
        this->typeEnum = INT_T;
    } else if (expr->typeEnum == BOOL_T) {
        this->typeEnum = BOOL_T;
    } else {
        throw "Error in PredFunc: expected either int or bool";
    }
}

Expr* PredFunc::op(Expr* expr) {
    auto expr_new = dynamic_cast<BoolConstExpr*>(expr);
    if (expr_new == nullptr) {
        auto expr_new = dynamic_cast<IntConstExpr*>(expr);
        if (expr_new == nullptr) {
            throw std::invalid_argument("Argument must be of type 'BoolConstExpr' or 'IntConstExpr'");
        } else {
            auto val = PredFunc::op(expr_new->value);

            return new IntConstExpr(val);
        }
    } else {
        auto val = PredFunc::op(expr_new->value);

        return new BoolConstExpr(val);
    }
}



bool PredFunc::op(bool val) {
    return !val;
}

int PredFunc::op(int val) {
    return --val;
}

std::string PredFunc::toString() const {
    return "pred(" + expr->toString() + ')';
}