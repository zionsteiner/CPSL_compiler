//
// Created by zion on 2/28/20.
//

#ifndef CPSL_COMPILER_CONSTASSIGN_H
#define CPSL_COMPILER_CONSTASSIGN_H


#include <classes/Expr/Ident.h>
#include <classes/Expr/Expr.h>

struct ConstAssign {
    const Ident* id;
    Expr* expr;

    ConstAssign(Ident*, Expr*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_CONSTASSIGN_H
