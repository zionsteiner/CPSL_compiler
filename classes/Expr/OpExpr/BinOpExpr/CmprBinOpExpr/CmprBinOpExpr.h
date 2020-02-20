//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_CMPRBINOPTEXPR_H
#define CPSL_COMPILER_CMPRBINOPTEXPR_H

#include "../BinOpExpr.h"

struct CmprBinOpExpr: BinOpExpr {
    CmprBinOpExpr(Expr*, Expr*);

    template <typename T>
    static Expr* binOp(Expr*, Expr*);
};


#endif //CPSL_COMPILER_CMPRBINOPTEXPR_H
