//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_CHRFUNC_H
#define CPSL_COMPILER_CHRFUNC_H

#include "../UnaryOpExpr.h"

struct ChrFunc: UnaryOpExpr {
    ChrFunc(Expr*);
    static Expr* op(Expr*);
    static char op(int);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
};


#endif //CPSL_COMPILER_CHRFUNC_H
