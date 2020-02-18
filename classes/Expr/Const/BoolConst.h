//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_BOOLCONST_H
#define CPSL_COMPILER_BOOLCONST_H

#include "Const.h"

struct BoolConst: Const {
    const bool value;

    BoolConst(value);
    void toString();
};


#endif //CPSL_COMPILER_BOOLCONST_H
