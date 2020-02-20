//
// Created by zion on 2/9/20.
//

#ifndef CPSL_COMPILER_EXPR_H
#define CPSL_COMPILER_EXPR_H

#include <string>

struct Expr {
    virtual bool isCompVal() = 0;
    virtual std::string toString() const = 0;
};


#endif //CPSL_COMPILER_EXPR_H