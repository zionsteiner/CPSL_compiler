//
// Created by zion on 2/17/20.
//

#include "UnaryMinus.h"

UnaryMinus::UnaryMinus(Expr* a): a(a) {}
static int UnaryMinus::op(int a) {return -a;}
void UnaryMinus::toString() {std::cout << '-' + a->toString();}
