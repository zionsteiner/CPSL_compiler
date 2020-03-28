//
// Created by zion on 2/14/20.
//

#ifndef CPSL_COMPILER_TYPE_H
#define CPSL_COMPILER_TYPE_H

#include <string>

struct Type {
    // ToDo: how to define this for different types?
    virtual int size() = 0;
    virtual std::string toString() const = 0;
    virtual ~Type() {};
};


#endif //CPSL_COMPILER_TYPE_H
