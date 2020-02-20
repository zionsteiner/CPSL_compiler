//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_LT_H
#define CPSL_COMPILER_LT_H

#include "CmprBinOpExpr.h"

struct LT: CmprBinOpExpr {
    LT(Expr*, Expr*);
    static bool binOp(int, int);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_LT_H
