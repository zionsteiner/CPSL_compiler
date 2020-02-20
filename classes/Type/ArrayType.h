//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_ARRAYTYPE_H
#define CPSL_COMPILER_ARRAYTYPE_H

#include <classes/Expr/Expr.h>
#include "Type.h"

struct ArrayType: Type {
    const Type* type;
    const Expr* begin;
    const Expr* end;

    ArrayType(Type*, Expr*, Expr*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_ARRAYTYPE_H
