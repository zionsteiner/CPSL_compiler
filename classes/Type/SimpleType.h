//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_SIMPLETYPE_H
#define CPSL_COMPILER_SIMPLETYPE_H

#include "Type.h"

struct SimpleType: Type {
    const Ident* id;

    SimpleType(Ident*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_SIMPLETYPE_H
