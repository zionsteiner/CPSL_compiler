//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_NOT_H
#define CPSL_COMPILER_NOT_H

#include "../OpExpr.h"

struct Not: OpExpr {
    const Expr* a;

    Not(Expr*);
    static bool op(bool);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_NOT_H
