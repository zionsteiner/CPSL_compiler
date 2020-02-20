//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_ARRAYTYPE_H
#define CPSL_COMPILER_ARRAYTYPE_H

#include <classes/Expr/Expr.h>
#include "Type.h"

struct ArrayType: Type {
    Type* type;
    Expr* begin;
    Expr* end;

    ArrayType(Type*, Expr*, Expr*);
    void toString():
};


#endif //CPSL_COMPILER_ARRAYTYPE_H
