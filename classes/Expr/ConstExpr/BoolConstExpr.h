//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_BOOLCONSTEXPR_H
#define CPSL_COMPILER_BOOLCONSTEXPR_H

#include <string>
#include "ConstExpr.h"

struct BoolConstExpr: Const {
    const bool value;

    explicit BoolConstExpr(bool);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_BOOLCONSTEXPR_H
