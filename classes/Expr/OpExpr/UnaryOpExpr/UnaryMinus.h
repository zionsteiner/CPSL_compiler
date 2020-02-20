//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_UNARYMINUS_H
#define CPSL_COMPILER_UNARYMINUS_H

#include "../OpExpr.h"
struct UnaryMinus: OpExpr {
    const Expr* a;

    UnaryMinus(Expr*);
    static int op(int);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_UNARYMINUS_H
