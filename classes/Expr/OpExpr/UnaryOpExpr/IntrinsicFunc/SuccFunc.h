//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_SUCCFUNC_H
#define CPSL_COMPILER_SUCCFUNC_H

#include <stdexcept>
#include "../UnaryOpExpr.h"
#include "../../../ConstExpr/IntConstExpr.h"
#include "../../../ConstExpr/BoolConstExpr.h"

struct SuccFunc: UnaryOpExpr {
    SuccFunc(Expr*);
    static Expr* op(Expr*);
    static int op(int);
    static bool op(bool);
    std::string toString() const override;
    RegisterPool::Register emitMips() override;
};


#endif //CPSL_COMPILER_SUCCFUNC_H
