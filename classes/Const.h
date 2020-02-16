//
// Created by zion on 2/10/20.
//

#ifndef CPSL_COMPILER_CONST_H
#define CPSL_COMPILER_CONST_H

#include "Expr.h"

struct Const: Expr {
    const int value;
    bool isCompVal();
    int compVal();
    print();

    Const( int );
};


#endif //CPSL_COMPILER_CONST_H
