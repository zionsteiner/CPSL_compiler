//
// Created by zion on 2/10/20.
//

#ifndef CPSL_COMPILER_CONST_H
#define CPSL_COMPILER_CONST_H

#include "expr.h"

struct Const: Expr {
    int  value

    bool isCompVal() { return true; }
    int compVal() { return value; }
    Const( int value ): value( value ){}
    print() { std::cout << value; }
};


#endif //CPSL_COMPILER_CONST_H
