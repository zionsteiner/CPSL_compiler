//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_ARITHBINOPEXPR_H
#define CPSL_COMPILER_ARITHBINOPEXPR_H

#include "../BinOpExpr.h"

struct ArithBinOpExpr: BinOpExpr {
    ArithBinOpExpr(Expr*, Expr*);
    static Expr* binOp(Expr*, Expr*);
    virtual static int binOp(int, int);
};


#endif //CPSL_COMPILER_ARITHBINOPEXPR_H
