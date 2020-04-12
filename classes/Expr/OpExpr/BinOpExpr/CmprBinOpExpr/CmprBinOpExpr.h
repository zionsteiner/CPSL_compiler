//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_CMPRBINOPTEXPR_H
#define CPSL_COMPILER_CMPRBINOPTEXPR_H

#include <iostream>
#include <classes/Expr/ConstExpr/IntConstExpr.h>
#include <classes/Expr/ConstExpr/BoolConstExpr.h>
#include "../BinOpExpr.h"

struct CmprBinOpExpr: BinOpExpr {
    CmprBinOpExpr(Expr*, Expr*);

    template<typename T>
    static Expr* binOp(Expr* a, Expr* b) {
        if (a->isCompVal() && b->isCompVal()) {
            auto a_new = dynamic_cast<IntConstExpr*> (a);
            auto b_new = dynamic_cast<IntConstExpr*> (b);
            bool val = T::binOp(a_new->value, b_new->value);

            return new BoolConstExpr(val);
        } else {
            return new T(a, b);
        }
    }
};

#endif //CPSL_COMPILER_CMPRBINOPTEXPR_H
