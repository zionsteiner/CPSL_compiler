//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_ORDFUNC_H
#define CPSL_COMPILER_ORDFUNC_H

#include "../UnaryOpExpr.h"

struct OrdFunc: UnaryOpExpr {
    OrdFunc(Expr* a);
    static Expr* op(Expr*);
    static int op(char);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_ORDFUNC_H
