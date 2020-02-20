//
// Created by zion on 2/20/20.
//

#ifndef CPSL_COMPILER_OPT_H
#define CPSL_COMPILER_OPT_H

#include <string>

struct Opt {
    bool _isEmtpy;
    bool isEmpty();
    virtual std::string toString() const = 0;
};

#endif //CPSL_COMPILER_OPT_H
