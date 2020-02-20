//
// Created by zion on 2/17/20.
//

#include "UnaryMinus.h"

UnaryMinus::UnaryMinus(Expr* a): a(a) {}
int UnaryMinus::op(int a) {return -a;}
std::string UnaryMinus::toString() const {
    return '-' + a->toString();
}
