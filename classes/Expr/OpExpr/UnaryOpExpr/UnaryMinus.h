//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_UNARYMINUS_H
#define CPSL_COMPILER_UNARYMINUS_H

#include "UnaryOpExpr.h"
#include "../../ConstExpr/IntConstExpr.h"

struct UnaryMinus: UnaryOpExpr {
    UnaryMinus(Expr*);
    static Expr* op(Expr*);
    static int op(int);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
};


#endif //CPSL_COMPILER_UNARYMINUS_H
