//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_ARRAYTYPE_H
#define CPSL_COMPILER_ARRAYTYPE_H

#include <classes/Expr/Expr.h>
#include <classes/Expr/ConstExpr/ConstExpr.h>
#include "Type.h"

struct ArrayType: Type {
    const ConstExpr* begin;
    const ConstExpr* end;
    Type* arrayType;

    ArrayType(Expr*, Expr*, Type*);
    std::string toString() const override;
    int size() override;
};


#endif //CPSL_COMPILER_ARRAYTYPE_H
