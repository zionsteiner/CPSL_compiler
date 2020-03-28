//
// Created by zion on 2/18/20.
//

#include "ArrayType.h"
#include <cstdio>

ArrayType::ArrayType(Expr* begin, Expr* end, Type* type): begin(begin), end(end), type(type) {}

std::string ArrayType::toString() const {
    return "array [ " + begin->toString() + ":" + end->toString() + " ] of " + type->toString();
}

int ArrayType::size() {return 0;}
