//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_LEQ_H
#define CPSL_COMPILER_LEQ_H

#include "CmprBinOpExpr.h"

struct Leq: CmprBinOpExpr {
    Leq(Expr*, Expr*);
    static bool binOp(int, int);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
};


#endif //CPSL_COMPILER_LEQ_H
