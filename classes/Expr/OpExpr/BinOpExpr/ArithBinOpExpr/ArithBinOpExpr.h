//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_ARITHBINOPEXPR_H
#define CPSL_COMPILER_ARITHBINOPEXPR_H

#include <classes/Expr/ConstExpr/IntConstExpr.h>
#include "../BinOpExpr.h"

struct ArithBinOpExpr: BinOpExpr {
    ArithBinOpExpr(Expr*, Expr*);

    template<typename T>
    static Expr* binOp(Expr* a, Expr* b) {
        if (a->isCompVal() && b->isCompVal()) {
            auto a = dynamic_cast<IntConstExpr*> (a);
            auto b = dynamic_cast<IntConstExpr*> (b);
            auto val = T::binOp(a->value, b->value);
            delete a;
            delete b;

            return new IntConstExpr(val);
        } else {
            return new T(a, b);
        }
    }
};


#endif //CPSL_COMPILER_ARITHBINOPEXPR_H
