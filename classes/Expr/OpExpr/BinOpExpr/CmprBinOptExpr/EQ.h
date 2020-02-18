//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_EQ_H
#define CPSL_COMPILER_EQ_H

#include "CmprBinOptExpr.h"

struct EQ: CmprBinOpExpr {
    EQ(Expr*, Expr*);
    static bool binOp(int, int);
    void toString();
};


#endif //CPSL_COMPILER_EQ_H
