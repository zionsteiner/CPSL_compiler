//
// Created by zion on 2/18/20.
//

#include "ArrayType.h"
#include <cstdio>

ArrayType::ArrayType(Type* type, Expr* begin, Expr* end): type(type), begin(begin), end(end) {}
std::string ArrayType::toString() const {
    return "array [ " + begin->toString() + ":" + end->toString() + " ] of " + type->toString();
}