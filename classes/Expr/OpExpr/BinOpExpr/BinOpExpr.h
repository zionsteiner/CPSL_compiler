//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_BINOPEXPR_H
#define CPSL_COMPILER_BINOPEXPR_H

#include "../OpExpr.h"

struct BinOpExpr: OpExpr {
    const Expr *a;
    const Expr* b;

    BinOpExpr(Expr*, Expr*);
    ~BinOpExpr();
};

#endif //CPSL_COMPILER_BINOPEXPR_H
