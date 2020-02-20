//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>
#include "IntConst.h"

IntConst::IntConst(int value): value(value) {}
std::string IntConst::toString() const {
    return std::to_string(value);
}