//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_STRCONSTEXPR_H
#define CPSL_COMPILER_STRCONSTEXPR_H


#include <string>
#include "ConstExpr.h"

struct StrConstExpr: ConstExpr {
    std::string value;
    StrConstExpr(const char*);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
};


#endif //CPSL_COMPILER_STRCONSTEXPR_H
