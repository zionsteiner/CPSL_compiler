//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_AMP_H
#define CPSL_COMPILER_AMP_H

#include "BoolBinOpExpr.h"

struct Amp: BoolBinOpExpr {
    Amp(Expr*, Expr*);
    static void binOp(int, int);
    void toString();
};


#endif //CPSL_COMPILER_AMP_H
