//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_GEQ_H
#define CPSL_COMPILER_GEQ_H

#include "CmprBinOptExpr.h"

struct GEQ: CmprBinOpExpr {
    GEQ(Expr*, Expr*);
    static bool binOp(int, int);
    void toString();
};


#endif //CPSL_COMPILER_GEQ_H
