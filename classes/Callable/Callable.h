//
// Created by zion on 3/9/20.
//

#ifndef CPSL_COMPILER_CALLABLE_H
#define CPSL_COMPILER_CALLABLE_H

#include <string>

struct Callable {
    virtual std::string toString() const = 0;
};

#endif //CPSL_COMPILER_CALLABLE_H