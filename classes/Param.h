//
// Created by zion on 2/19/20.
//

#ifndef CPSL_COMPILER_PARAM_H
#define CPSL_COMPILER_PARAM_H

#include <vector>
#include "Expr/Ident.h"
#include "Type/Type.h"

struct Param {
    const bool isPassByRef;
    const std::vector<Ident*>* idList;
    Type* type;

    Param(bool, std::vector<Ident*>*, Type*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_PARAM_H
