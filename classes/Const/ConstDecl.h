//
// Created by zion on 3/9/20.
//

#ifndef CPSL_COMPILER_CONSTDECL_H
#define CPSL_COMPILER_CONSTDECL_H

#include <vector>
#include "ConstAssign.h"

struct ConstDecl {
    const std::vector<ConstAssign*>* constAssignList;

    explicit ConstDecl(std::vector<ConstAssign*>*);
    std::string toString() const;
    void emitMips() const;
};


#endif //CPSL_COMPILER_CONSTDECL_H
