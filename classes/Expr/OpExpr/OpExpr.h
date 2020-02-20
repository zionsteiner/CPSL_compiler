//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_OP_H
#define CPSL_COMPILER_OP_H

#include "../Expr.h"

struct OpExpr: Expr {
    bool isCompVal() override;
};


#endif //CPSL_COMPILER_OP_H
