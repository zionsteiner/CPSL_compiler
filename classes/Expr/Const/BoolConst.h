//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_BOOLCONST_H
#define CPSL_COMPILER_BOOLCONST_H

#include <string>
#include "Const.h"

struct BoolConst: Const {
    const bool value;

    explicit BoolConst(bool);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_BOOLCONST_H
