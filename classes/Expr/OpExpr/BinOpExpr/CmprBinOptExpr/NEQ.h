//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_NEQ_H
#define CPSL_COMPILER_NEQ_H

#include "CmprBinOptExpr.h

struct NEQ: CmprBinOpExpr {
    NEQ(Expr*, Expr*);
    static bool binOp(int, int);
    void toString();
};


#endif //CPSL_COMPILER_NEQ_H
