//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_SUB_H
#define CPSL_COMPILER_SUB_H

#include "ArithBinOpExpr.h"

struct Sub: ArithBinOpExpr {
    Sub(Expr*, Expr*);
    static int binOp(int, int);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
    static RegisterPool::Register emitMips(Expr*, Expr*);
    static RegisterPool::Register emitMips(RegisterPool::Register&, RegisterPool::Register&);
};


#endif //CPSL_COMPILER_SUB_H
