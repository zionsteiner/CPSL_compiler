//
// Created by zion on 2/20/20.
//

#ifndef CPSL_COMPILER_VARDECL_H
#define CPSL_COMPILER_VARDECL_H


#include "VarAssign.h"
#include <iostream>

struct VarDecl {
    const std::vector<VarAssign*>* varAssignList;

    explicit VarDecl(std::vector<VarAssign*>*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_VARDECL_H
