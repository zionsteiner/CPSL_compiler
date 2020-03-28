//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_CMPRBINOPTEXPR_H
#define CPSL_COMPILER_CMPRBINOPTEXPR_H

#include <classes/Expr/ConstExpr/BoolConstExpr.h>
#include "../BinOpExpr.h"

struct CmprBinOpExpr: BinOpExpr {
    CmprBinOpExpr(Expr*, Expr*);

    template<typename T>
    static Expr* binOp(Expr* a, Expr* b) {
        if (a->isCompVal() && b->isCompVal()) {
            auto a = dynamic_cast<BoolConstExpr*> (a);
            auto b = dynamic_cast<BoolConstExpr*> (b);
            auto val = T::binOp(a->value, b->value);
            delete a;
            delete b;

            return new BoolConstExpr(val);
        } else {
            return new T(a, b);
        }
    }
};

#endif //CPSL_COMPILER_CMPRBINOPTEXPR_H
