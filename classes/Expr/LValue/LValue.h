//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_LVALUE_H
#define CPSL_COMPILER_LVALUE_H

#include <vector>
#include <List/DotOrIndexPlus.h>
#include <Expr/Ident.h>
#include "Expr/Expr.h"

struct LValue: Expr {
    const Ident* id;
    const DotOrIndexPlus* exts;

    LValue(Ident*, DotOrIndexPlus*);
    std::string toString() const override;
    bool isCompVal() override;
};


#endif //CPSL_COMPILER_LVALUE_H
