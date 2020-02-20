//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_STRCONST_H
#define CPSL_COMPILER_STRCONST_H


#include <string>
#include "Const.h"

class StrConst: Const {
    const std::string value;
    StrConst(char*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_STRCONST_H
