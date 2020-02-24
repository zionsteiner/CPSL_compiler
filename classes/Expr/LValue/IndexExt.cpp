//
// Created by zion on 2/23/20.
//

#include "IndexExt.h"

IndexExt::IndexExt(Expr* a): a(a) {}
std::string IndexExt::toString() const {
    return '[' + a->toString() + ']';
}