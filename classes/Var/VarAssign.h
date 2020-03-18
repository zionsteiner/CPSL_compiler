//
// Created by zion on 2/19/20.
//

#ifndef CPSL_COMPILER_VARASSIGN_H
#define CPSL_COMPILER_VARASSIGN_H

#include <string>
#include "classes/Type/Type.h"

struct VarAssign {
    const std::vector<Ident*> idList;
    const Type* type;

    VarAssign(std::vector<Ident*>*, Type*);
    std::string toString() const;
    ~VarAssign();
};


#endif //CPSL_COMPILER_VARASSIGN_H
