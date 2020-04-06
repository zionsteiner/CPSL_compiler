//
// Created by zion on 2/17/20.
//

#include <iostream>
#include <sstream>
#include "BoolConstExpr.h"

BoolConstExpr::BoolConstExpr(bool value): value(value) {}
std::string BoolConstExpr::toString() const {
    std::string retStr = value? "true": "false";

    return retStr;
}
