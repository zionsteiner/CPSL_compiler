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
    std::string base;
    bool isRef;

    Symbol(int, Type*, bool);
    Symbol(Expr*, Type*, bool);
    Symbol(const Expr* Expr, Type*, bool);
    RegisterPool::Register emitMips();
    Type* getType();
};


#endif //CPSL_COMPILER_SYMBOL_H
