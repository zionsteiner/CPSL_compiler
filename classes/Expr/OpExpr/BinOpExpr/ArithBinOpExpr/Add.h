//
// Created by zion on 2/14/20.
//

#ifndef CPSL_COMPILER_ADD_H
#define CPSL_COMPILER_ADD_H

#include "ArithBinOpExpr.h"

struct Add: ArithBinOpExpr {
    Add(Expr*, Expr*);
    static int binOp(int, int);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
    static RegisterPool::Register emitMips(RegisterPool::Register&, RegisterPool::Register&);
};


#endif //CPSL_COMPILER_ADD_H
