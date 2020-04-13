//
// Created by zion on 2/27/20.
//

#include <globals.h>
#include <iostream>
#include <classes/Type/ArrayType.h>
#include <classes/Type/RecordType.h>
#include "AssnStmt.h"

AssnStmt::AssnStmt(LValue* lVal, Expr* expr): lVal(lVal), expr(expr) {}

std::string AssnStmt::toString() const {
    return lVal->toString() + " := " + expr->toString();
}

void AssnStmt::emitMips() {
    int baseOffset = lVal->lookupBaseOffset();

    if (baseOffset != -1) {
        std::cout << "# Assignment" << std::endl;

        // Copy UDT
        auto assnLVal = dynamic_cast<LValue*>(expr);
        if (assnLVal != nullptr) {
            // Type check
            auto lValType = lVal->lookupType();
            auto exprType = assnLVal->lookupType();
            if (lValType != exprType) {
                std::invalid_argument("ERROR: incompatible types for assignment");
            }

            if (lValType->typeEnum == ARRAY_T) {
                std::cout << "# Copy array" << std::endl;

                // Get base addresses
                auto lValAddrReg = lVal->emitAddr();
                auto assnLValAddrReg = assnLVal->emitAddr();

                // Get array size
                int assnSize = assnLVal->lookupType()->size();

                // Copy
                for (int i = 0; i < assnSize; i += 4) {
                    auto copyReg = registerPool.get();
                    std::cout << "lw " + copyReg.getRegId() + ", " + std::to_string(i) + "(" + assnLValAddrReg.getRegId() + ")" << std::endl;
                    std::cout << "sw " + copyReg.getRegId() + ", " + std::to_string(i) + "(" + lValAddrReg.getRegId() + ")" << std::endl;
                }
            } else if (lValType->typeEnum == RECORD_T) {
                auto lValRecordType = dynamic_cast<RecordType*>(lValType);
                auto assnRecordType = dynamic_cast<RecordType*>(exprType);


                std::cout << "# Copy record" << std::endl;

                // Get base addresses
                auto lValAddrReg = lVal->emitAddr();
                auto assnLValAddrReg = assnLVal->emitAddr();

                // Get record size
                int assnSize = assnLVal->lookupType()->size();

                // Copy
                auto copyReg = registerPool.get();
                for (int i = 0; i < assnSize; i += 4) {
                    std::cout << "lw " + copyReg.getRegId() + ", " + std::to_string(i) + "(" + assnLValAddrReg.getRegId() + ")" << std::endl;
                    std::cout << "sw " + copyReg.getRegId() + ", " + std::to_string(i) + "(" + lValAddrReg.getRegId() + ")" << std::endl;
                }
            } else {
                    auto lValAddrReg = lVal->emitAddr();
                    auto reg = expr->emitMips();
                    std::cout << "sw " + reg.getRegId() + ", (" + lValAddrReg.getRegId() + ")" << std::endl;
            }
        } else {
            auto lValAddrReg = lVal->emitAddr();
            auto reg = expr->emitMips();
            std::cout << "sw " + reg.getRegId() + ", (" + lValAddrReg.getRegId() + ")" << std::endl;
        }

    } else {
        throw std::invalid_argument("ERROR: attempt to assign to non-var");
    }
}