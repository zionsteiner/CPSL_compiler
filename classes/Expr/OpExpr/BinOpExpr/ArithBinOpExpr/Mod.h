//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_MOD_H
#define CPSL_COMPILER_MOD_H

#include "ArithBinOpExpr.h"

struct Mod: ArithBinOpExpr {
    Mod(Expr*, Expr*);

    static int binOp(int, int);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
};


#endif //CPSL_COMPILER_MOD_H
