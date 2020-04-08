//
// Created by zion on 2/24/20.
//

#ifndef CPSL_COMPILER_STMT_H
#define CPSL_COMPILER_STMT_H


#include <string>
#include "RegisterPool.h"

struct Stmt {
    virtual std::string toString() const = 0;
    virtual void emitMips() {};
};


#endif //CPSL_COMPILER_STMT_H
