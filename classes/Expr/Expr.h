//
// Created by zion on 2/9/20.
//

#ifndef CPSL_COMPILER_EXPR_H
#define CPSL_COMPILER_EXPR_H

#include <string>
#include <RegisterPool.h>
#include <classes/Type/Type.h>

struct Expr {
    TypeEnum typeEnum;

    Expr() = default;
    Expr(TypeEnum typeEnum): typeEnum(typeEnum) {}
    virtual bool isCompVal() = 0;
    virtual std::string toString() const = 0;
    virtual RegisterPool::Register emitMips() = 0;
};


#endif //CPSL_COMPILER_EXPR_H