//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_GT_H
#define CPSL_COMPILER_GT_H

#include "CmprBinOptExpr.h"

struct GT: CmprBinOpExpr {
    GT(Expr*, Expr*);
    static bool binOp(int, int);
    void toString();
};


#endif //CPSL_COMPILER_GT_H
