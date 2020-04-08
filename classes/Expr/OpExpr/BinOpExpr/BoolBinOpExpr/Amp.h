//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_AMP_H
#define CPSL_COMPILER_AMP_H

#include "BoolBinOpExpr.h"
#include "Amp.h"

struct Amp: BoolBinOpExpr {
    Amp(Expr*, Expr*);
    static bool binOp(int, int);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
};


#endif //CPSL_COMPILER_AMP_H
