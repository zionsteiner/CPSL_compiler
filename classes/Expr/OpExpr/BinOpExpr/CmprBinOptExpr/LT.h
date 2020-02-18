//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_LT_H
#define CPSL_COMPILER_LT_H

#include "CmprBinOptExpr.h"

struct LT: CmprBinOpExpr {
    LT(Expr*, Expr*);
    static bool binOp(int, int);
    void toString();
};


#endif //CPSL_COMPILER_LT_H
