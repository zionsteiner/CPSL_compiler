//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_NOT_H
#define CPSL_COMPILER_NOT_H

#include "../OpExpr.h"
#include "UnaryOpExpr.h"
#include "../../../Expr/ConstExpr/BoolConstExpr.h"

struct Not: UnaryOpExpr {
    Not(Expr*);
    static Expr* op(Expr*);
    static bool op(bool);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
};


#endif //CPSL_COMPILER_NOT_H
