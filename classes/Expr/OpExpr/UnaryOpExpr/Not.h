//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_NOT_H
#define CPSL_COMPILER_NOT_H

#include "../OpExpr.h"

struct Not: OpExpr {
    const Expr* a;

    Not(Expr*);
    ~Not();
    static bool op(bool);
    void toString();
};


#endif //CPSL_COMPILER_NOT_H
