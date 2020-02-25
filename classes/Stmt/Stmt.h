//
// Created by zion on 2/24/20.
//

#ifndef CPSL_COMPILER_STMT_H
#define CPSL_COMPILER_STMT_H


#include <string>

struct Stmt {
    virtual std::string toString() const;
};


#endif //CPSL_COMPILER_STMT_H
