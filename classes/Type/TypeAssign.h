//
// Created by zion on 3/12/20.
//

#ifndef CPSL_COMPILER_TYPEASSIGN_H
#define CPSL_COMPILER_TYPEASSIGN_H


#include <classes/Expr/Ident.h>
#include "Type.h"

struct TypeAssign {
    const Ident* id;
    Type* type;

    TypeAssign(Ident*, Type*);
    std::string toString() const;
    void emitMips();
};


#endif //CPSL_COMPILER_TYPEASSIGN_H
