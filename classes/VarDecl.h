//
// Created by zion on 2/20/20.
//

#ifndef CPSL_COMPILER_VARDECL_H
#define CPSL_COMPILER_VARDECL_H


#include <classes/List/VarAssignList.h>

struct VarDecl {
    const VarAssignList* list;

    explicit VarDecl(VarAssignList*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_VARDECL_H
