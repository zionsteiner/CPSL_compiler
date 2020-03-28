//
// Created by zion on 2/10/20.
//

#ifndef CPSL_COMPILER_CONSTEXPR_H
#define CPSL_COMPILER_CONSTEXPR_H

#include "../Expr.h"


struct ConstExpr: Expr {
    bool isCompVal() override;
};


#endif //CPSL_COMPILER_CONSTEXPR_H
