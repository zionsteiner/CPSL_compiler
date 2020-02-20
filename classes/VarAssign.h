//
// Created by zion on 2/19/20.
//

#ifndef CPSL_COMPILER_VARASSIGN_H
#define CPSL_COMPILER_VARASSIGN_H


#include <classes/List/idList.h>
#include <string>
#include "classes/Type/Type.h"

struct VarAssign {
    const idList* idList;
    const Type* type;

    VarAssign(idList*, Type*);
    std::string toString() const;
    ~VarAssign();
};


#endif //CPSL_COMPILER_VARASSIGN_H
