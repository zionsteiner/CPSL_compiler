//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_DIV_H
#define CPSL_COMPILER_DIV_H

#include "ArithBinOpExpr.h"

struct Div: ArithBinOpExpr {
    Div(Expr*, Expr*);
    static int binOp(int, int);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_DIV_H
