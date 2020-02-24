//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_SUCCFUNC_H
#define CPSL_COMPILER_SUCCFUNC_H

#include "../UnaryOpExpr.h"

struct SuccFunc: UnaryOpExpr {
    SuccFunc(Expr* a);
    static Expr* op(Expr*);
    static int op(int);
    static bool op(bool);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_SUCCFUNC_H
