//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_ARRAYTYPE_H
#define CPSL_COMPILER_ARRAYTYPE_H

#include <classes/Expr/Expr.h>
#include <classes/Expr/ConstExpr/ConstExpr.h>
#include "Type.h"

struct ArrayType: Type {
    Expr* begin;
    Expr* end;
    Type* arrayType;
    int m_size;

    ArrayType(Expr*, Expr*, Type*);
    std::string toString() const override;
    int size() override;
    void emitMips();
};


#endif //CPSL_COMPILER_ARRAYTYPE_H
