//
// Created by zion on 3/12/20.
//

#ifndef CPSL_COMPILER_TYPEDECL_H
#define CPSL_COMPILER_TYPEDECL_H


#include "TypeAssign.h"
#include <vector>

struct TypeDecl {
    const std::vector<TypeAssign*>* typeAssignPlus;

    explicit TypeDecl(std::vector<TypeAssign*>*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_TYPEDECL_H
