//
// Created by zion on 4/11/20.
//

#ifndef CPSL_COMPILER_SIMPLETYPE_H
#define CPSL_COMPILER_SIMPLETYPE_H

#include "Type.h"
#include "../Expr/Ident.h"

struct SimpleType: Type {
    Ident* id;
    std::string toString() const override;
    SimpleType(Ident* id);
    int size();
};


#endif //CPSL_COMPILER_SIMPLETYPE_H
