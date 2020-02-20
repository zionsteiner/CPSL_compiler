//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_BOOLBINOPEXPR_H
#define CPSL_COMPILER_BOOLBINOPEXPR_H

#include "../BinOpExpr.h"

struct BoolBinOpExpr: BinOpExpr {
    BoolBinOpExpr(Expr*, Expr*);

    template<typename T>
    static Expr* binOp(Expr*, Expr*);
    virtual static bool binOp(bool, bool);
};


#endif //CPSL_COMPILER_BOOLBINOPEXPR_H
