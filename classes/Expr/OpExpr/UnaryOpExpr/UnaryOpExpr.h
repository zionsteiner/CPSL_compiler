//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_UNARYOPEXPR_H
#define CPSL_COMPILER_UNARYOPEXPR_H

#include <Expr/Expr.h>

struct UnaryOpExpr: Expr {
    const Expr* a;

    explicit UnaryOpExpr(Expr*);
    bool isCompVal() override;
};


#endif //CPSL_COMPILER_UNARYOPEXPR_H
