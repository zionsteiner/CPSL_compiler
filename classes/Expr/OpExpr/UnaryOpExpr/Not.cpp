//
// Created by zion on 2/17/20.
//

#include "Not.h"

Not::Not(Expr* a): a(a) {}
Not::~Not() {delete a;}
static bool Not::op(bool a) {return !a;}
void Not::toString() {std::cout << '~' + a->toString();}