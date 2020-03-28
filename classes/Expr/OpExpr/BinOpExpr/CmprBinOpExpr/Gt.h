//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_GT_H
#define CPSL_COMPILER_GT_H

#include "CmprBinOpExpr.h"

struct Gt: CmprBinOpExpr {
    Gt(Expr*, Expr*);
    static bool binOp(int, int);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_GT_H
