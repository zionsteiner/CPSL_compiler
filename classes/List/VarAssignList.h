//
// Created by zion on 2/19/20.
//

#ifndef CPSL_COMPILER_VARASSIGNLIST_H
#define CPSL_COMPILER_VARASSIGNLIST_H

#include <classes/VarAssign.h>
#include "List.h"

struct VarAssignList: List {
    std::vector<VarAssign*> list;

    VarAssignList();
    void append(VarAssign*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_VARASSIGNLIST_H
