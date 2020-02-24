//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_EXT_H
#define CPSL_COMPILER_EXT_H


#include <string>

struct Ext {
    virtual std::string toString() const = 0;
};


#endif //CPSL_COMPILER_EXT_H
