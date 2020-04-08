//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_CHRCONSTEXPR_H
#define CPSL_COMPILER_CHRCONSTEXPR_H

#include "ConstExpr.h"

struct ChrConstExpr: ConstExpr {
    const char value;

    explicit ChrConstExpr(char);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
};


#endif //CPSL_COMPILER_CHRCONSTEXPR_H
