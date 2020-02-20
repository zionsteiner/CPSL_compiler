//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>
#include "Not.h"

Not::Not(Expr* a): a(a) {}
bool Not::op(bool a) {return !a;}
std::string Not::toString() const {
    return '~' + a->toString();
}