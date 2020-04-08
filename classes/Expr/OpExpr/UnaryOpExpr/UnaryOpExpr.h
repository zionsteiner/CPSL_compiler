//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_UNARYOPEXPR_H
#define CPSL_COMPILER_UNARYOPEXPR_H

#include "../../Expr.h"

struct UnaryOpExpr: Expr {
    Expr *expr;

    explicit UnaryOpExpr(Expr*);
    UnaryOpExpr(Expr*, TypeEnum);
    bool isCompVal() override;
};


#endif //CPSL_COMPILER_UNARYOPEXPR_H
