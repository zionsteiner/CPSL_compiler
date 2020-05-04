//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_BOOLBINOPEXPR_H
#define CPSL_COMPILER_BOOLBINOPEXPR_H

#include <classes/Expr/ConstExpr/BoolConstExpr.h>
#include "../BinOpExpr.h"

struct BoolBinOpExpr: BinOpExpr {
    BoolBinOpExpr(Expr*, Expr*);

    template<typename T>
    static Expr* binOp(Expr* a, Expr* b) {
        return new T(a, b);
    }
//        if (a->isCompVal() && b->isCompVal()) {
//            auto a_new = dynamic_cast<BoolConstExpr*> (a);
//            auto b_new = dynamic_cast<BoolConstExpr*> (b);
//            auto val = T::binOp(a_new->value, b_new->value);
//
//            return new BoolConstExpr(val);
//        } else {
//            return new T(a, b);
//        }
//    }
};

#endif //CPSL_COMPILER_BOOLBINOPEXPR_H
