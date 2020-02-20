//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_INTCONST_H
#define CPSL_COMPILER_INTCONST_H

#include "Const.h"

struct IntConst: Const {
    const int value;
    explicit IntConst(int);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_INTCONST_H
