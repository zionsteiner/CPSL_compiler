//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_BAR_H
#define CPSL_COMPILER_BAR_H

#include "BoolBinOpExpr.h"

struct Bar: BoolBinOpExpr {
    Bar(Expr*, Expr*);
    static bool binOp(bool, bool);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_BAR_H
