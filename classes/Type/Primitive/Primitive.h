//
// Created by zion on 2/24/20.
//

#ifndef CPSL_COMPILER_PRIMITIVE_H
#define CPSL_COMPILER_PRIMITIVE_H

#include "Type/Type.h"

struct Primitive: Type {
    int size() override;
};


#endif //CPSL_COMPILER_PRIMITIVE_H
