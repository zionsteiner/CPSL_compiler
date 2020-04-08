//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_BOOLCONSTEXPR_H
#define CPSL_COMPILER_BOOLCONSTEXPR_H

#include <string>
#include "ConstExpr.h"

struct BoolConstExpr: ConstExpr {
    const bool value;

    explicit BoolConstExpr(bool);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
};


#endif //CPSL_COMPILER_BOOLCONSTEXPR_H
