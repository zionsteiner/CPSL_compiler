//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_CHRCONST_H
#define CPSL_COMPILER_CHRCONST_H

#include "Const.h"

struct ChrConst: Const {
    const char value;

    explicit ChrConst(char);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_CHRCONST_H
