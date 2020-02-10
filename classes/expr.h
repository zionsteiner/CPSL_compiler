//
// Created by zion on 2/9/20.
//

#ifndef CPSL_COMPILER_EXPR_H
#define CPSL_COMPILER_EXPR_H


struct Expr {
    virtual bool isCompVal = 0;
    virtual int compVal() = 0;
    virtual Register emit() = 0;
    virtual void print() = 0;
};


#endif //CPSL_COMPILER_EXPR_H
