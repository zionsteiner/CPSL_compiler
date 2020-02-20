//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>
#include "BoolConst.h"

BoolConst::BoolConst(bool value): value(value) {}
std::string BoolConst::toString() const {
    std::stringstream buffer;
    buffer << value;

    return buffer.str();
}
