//
// Created by zion on 4/6/20.
//

#ifndef CPSL_COMPILER_SYMBOL_H
#define CPSL_COMPILER_SYMBOL_H


#include <classes/Expr/Expr.h>
#include <classes/Type/Type.h>

struct Symbol {
    int offset;
    Expr* expr;
    Type* type;

    explicit Symbol(int, Type*);
    explicit Symbol(Expr*, Type*);
    Symbol(const Expr* Expr, Type*);
};


#endif //CPSL_COMPILER_SYMBOL_H
