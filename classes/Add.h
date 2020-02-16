//
// Created by zion on 2/14/20.
//

#ifndef CPSL_COMPILER_ADD_H
#define CPSL_COMPILER_ADD_H

#include "Expr.h"

struct Add: Expr {
    Add* add( Expr, Expr );
    Add( Expr, Expr );
};


#endif //CPSL_COMPILER_ADD_H
