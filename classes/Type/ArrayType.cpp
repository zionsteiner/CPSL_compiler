//
// Created by zion on 2/18/20.
//

#include "ArrayType.h"
#include <cstdio>

ArrayType::ArrayType(Expr* begin, Expr* end, Type* type): Type(ARRAY_T), begin(begin), end(end), arrayType(arrayType) {}

std::string ArrayType::toString() const {
    return "array [ " + begin->toString() + ":" + end->toString() + " ] of " + arrayType->toString();
}

int ArrayType::size() {return 0;}
