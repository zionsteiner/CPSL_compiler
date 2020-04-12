//
// Created by zion on 2/18/20.
//

#include "ArrayType.h"
#include "SimpleType.h"
#include <classes/Expr/ConstExpr/ConstExpr.h>
#include <stdexcept>
#include <classes/Expr/OpExpr/UnaryOpExpr/IntrinsicFunc/OrdFunc.h>
#include <classes/Expr/ConstExpr/IntConstExpr.h>
#include <classes/Expr/ConstExpr/ChrConstExpr.h>
#include <classes/Expr/LValue/LValue.h>
#include <globals.h>

ArrayType::ArrayType(Expr* begin, Expr* end, Type* arrayType): Type(ARRAY_T) {
    // Type check array bounds
    auto lValBegin = dynamic_cast<LValue*>(begin);
    if (lValBegin != nullptr) {
        auto symbol = lValBegin->getSymbol();
        begin = symbol->expr;

    }

    auto lValEnd = dynamic_cast<LValue*>(end);
    if (lValEnd != nullptr) {
        if (lValEnd != nullptr) {
            auto symbol = lValEnd->getSymbol();
            end = symbol->expr;
        } else {
            throw std::invalid_argument("Array bounds must be known at compile time");
        }
    }

    auto constBegin = dynamic_cast<ConstExpr*>(begin);
    if (constBegin != nullptr) {
        this->begin = constBegin;
    }

    auto constEnd = dynamic_cast<ConstExpr*>(end);
    if (constEnd != nullptr) {
        this->end = constEnd;
    }

    // Calculate array size
    int beginVal = -1;
    int endVal = -1;

    auto chrBegin = dynamic_cast<const ChrConstExpr*>(begin);
    if (chrBegin != nullptr) {
        beginVal = OrdFunc::op(chrBegin->value);
    }
    auto intBegin = dynamic_cast<const IntConstExpr*>(begin);
    if (intBegin != nullptr) {
        beginVal = intBegin->value;
    }
    if (beginVal == -1) {
        throw std::runtime_error("ERROR: invalid const expression used for setting array bounds");
    }

    auto chrEnd = dynamic_cast<const ChrConstExpr*>(end);
    if (chrEnd != nullptr) {
        endVal = OrdFunc::op(chrEnd->value);
    }
    auto intEnd = dynamic_cast<const IntConstExpr*>(end);
    if (intEnd != nullptr) {
        endVal = intEnd->value;
    }
    if (endVal == -1) {
        throw std::runtime_error("ERROR: invalid const expression used for setting array bounds");
    }

    // Set size
    m_size = arrayType->size() * (endVal - beginVal + 1);

    if (m_size < 0 || beginVal == -1 || endVal == -1) {
        throw std::invalid_argument("ERROR: invalid array size (negative)");
    }

    // Set type
    auto s_type = dynamic_cast<SimpleType*>(arrayType);
    if (s_type == nullptr) {
        this->arrayType = arrayType;
    } else {
        this->arrayType = s_type->lookupType();
    }
}

std::string ArrayType::toString() const {
    return "array [" + begin->toString() + ":" + end->toString() + "] of " + arrayType->toString();
}

int ArrayType::size() {
    return m_size;
}
