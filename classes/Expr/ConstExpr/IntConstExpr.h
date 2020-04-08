//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_INTCONSTEXPR_H
#define CPSL_COMPILER_INTCONSTEXPR_H

#include "ConstExpr.h"

struct IntConstExpr: ConstExpr {
    const int value;
    explicit IntConstExpr(int);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
};


#endif //CPSL_COMPILER_INTCONSTEXPR_H
