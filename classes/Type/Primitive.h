//
// Created by zion on 2/24/20.
//

#ifndef CPSL_COMPILER_PRIMITIVE_H
#define CPSL_COMPILER_PRIMITIVE_H

#include "Type.h"

struct Primitive: Type {
    TypeEnum typeEnum;
    std::string toString() const override;
    explicit Primitive(TypeEnum);
    ~Primitive() override = default;
    int size() override;
};


#endif //CPSL_COMPILER_PRIMITIVE_H
