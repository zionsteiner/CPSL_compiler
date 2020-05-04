//
// Created by zion on 2/23/20.
//

#include <globals.h>
#include <classes/Expr/ConstExpr/ConstExpr.h>
#include <classes/Type/ArrayType.h>
#include <classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Sub.h>
#include <classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Mult.h>
#include <iostream>
#include <classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Add.h>
#include <classes/Type/RecordType.h>
#include "LValue.h"
#include "IndexExt.h"
#include "DotExt.h"

LValue::LValue(Ident* id, std::vector<Ext*>* exts): Expr(SIMPLE_T), id(id), exts(exts) {}
std::string LValue::toString() const {
    std::string retStr;
    retStr += id->toString();
    if (exts != nullptr) {
        for (auto ext = exts->begin(); ext != exts->end(); ++ext) {
            retStr += (*ext)->toString();
        }
    }

    return retStr;
}

// Return temp symbol for lookup if not base
Symbol* LValue::getSymbol() {
    Symbol* symbol = symbolTable.lookupSymbol(id->id);
    return symbol;
}

bool LValue::isCompVal() {
    auto symbol = getSymbol();
    if (symbol != nullptr) {
        auto expr = symbol->expr;
        if (expr != nullptr) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

Type* LValue::lookupType() {
    Symbol* symbol = getSymbol();

    Type* currType = symbol->getType();

    // Lookup type of extensions
    if (exts != nullptr) {
        for (auto ext = exts->begin(); ext != exts->end(); ++ext) {
            auto indexExt = dynamic_cast<IndexExt*>((*ext));
            if (indexExt != nullptr) {
                // CASE: ARRAY
                if (currType->typeEnum == ARRAY_T) {
                    ArrayType* arrayType = dynamic_cast<ArrayType*>(currType);
                    currType = arrayType->arrayType;
                } else {
                    throw std::runtime_error("ERROR: array indexing can only be used on arrays");
                }
            }

            auto dotExt = dynamic_cast<DotExt*>((*ext));
            if (dotExt != nullptr) {
                // CASE: RECORD
                if (currType->typeEnum == RECORD_T) {
                    auto recordType = dynamic_cast<RecordType*>(currType);
                    currType = recordType->lookupType(dotExt->id->id);
                } else {
                    throw std::runtime_error("ERROR: dot accessing can only be used on records");
                }
            }
        }
    }

    return currType;
}

std::string LValue::lookupBase() {
    auto symbol = getSymbol();
    return symbol->base;
}

int LValue::lookupBaseOffset() {
    auto symbol = getSymbol();
    return symbol->offset - symbolTable.getFpOffset();
}

RegisterPool::Register LValue::emitMips() {
    Symbol* symbol = getSymbol();

    // 1. Find address of first word
    Type* currType = symbol->getType();
    std::cout << "# LVal" << std::endl;
    auto currOffsetReg = registerPool.get();

    if (symbol->isRef) {
        std::cout << "lw " + currOffsetReg.getRegId() + ", " + std::to_string(lookupBaseOffset()) + "(" + lookupBase() + ")" << std::endl;
    } else {
        int currOffset = lookupBaseOffset();
        std::cout << "li " + currOffsetReg.getRegId() + ", " + std::to_string(currOffset) << std::endl;
        std::cout << "sub " + currOffsetReg.getRegId() + ", "  + lookupBase() + ", " + currOffsetReg.getRegId() << std::endl;
    }

    if (symbol->offset != -1) {
        // Lookup lVal extensions
        if (exts != nullptr) {
            for (auto ext = exts->begin(); ext != exts->end(); ++ext) {
                auto indexExt = dynamic_cast<IndexExt *>((*ext));

                if (indexExt != nullptr) {
                    // CASE: ARRAY
                    if (currType->typeEnum == ARRAY_T) {
                        ArrayType *arrayType = dynamic_cast<ArrayType *>(currType);
                        ConstExpr *lowIndex = dynamic_cast<ConstExpr *>(arrayType->begin);

                        // 2. Compute indexing expression
                        Expr *indexExpr = const_cast<Expr *>(indexExt->a);

                        // 3. Find position of element (nth)
                        auto indexReg = Sub::emitMips(indexExpr, (Expr *) lowIndex);

                        // 4. Find offset from array base
                        // Load array element from size
                        auto elementSizeReg = registerPool.get();
                        int elementSize = arrayType->arrayType->size();
                        std::cout << "li " + elementSizeReg.getRegId() + ", " + std::to_string(elementSize)
                                  << std::endl;
                        // Calculate offset
                        auto offsetReg = Mult::emitMips(indexReg, elementSizeReg);

                        // 5. Sub offset from array base
                        currOffsetReg = Sub::emitMips(currOffsetReg, offsetReg);

                        // Update currType
                        currType = arrayType->arrayType;

//                        {
//                            auto t = dynamic_cast<IntConstExpr*>(indexExpr);
//                            if (t != nullptr) {
//                                int t1 = t->value;
//                                if (t1 == 3) {
//                                    std::string strId = symbolTable.addString("ADDR: ");
//                                    std::cout << "la $a0, " + strId << std::endl;
//                                    std::cout << "li $v0, 4" << std::endl;
//                                    std::cout << "syscall" << std::endl;
//                                    std::cout << "move $a0, " + currOffsetReg.getRegId() << std::endl;
//                                    std::cout << "li $v0, 1" << std::endl;
//                                    std::cout << "syscall" << std::endl;
//                                    std::cout << "li $a0, '\\n'" << std::endl;
//                                    std::cout << "li $v0, 11" << std::endl;
//                                    std::cout << "syscall" << std::endl;
//                                }
//                            }
//                        }
                    } else {
                        // ToDo: record errors and print in mips
                        throw std::runtime_error("ERROR: array indexing can only be used on arrays");
                    }
                }

                auto dotExt = dynamic_cast<DotExt *>((*ext));

                if (dotExt != nullptr) {
                    // CASE: RECORD
                    if (currType->typeEnum == RECORD_T) {
                        RecordType *recordType = dynamic_cast<RecordType *>(currType);
                        std::string dotId = dotExt->id->id;
                        int currOffset = recordType->lookupOffset(dotId);

                        // Add offset to reg
                        auto tempCurrOffsetReg = registerPool.get();
                        std::cout << "li " + tempCurrOffsetReg.getRegId() + ", " + std::to_string(currOffset)
                                  << std::endl;
                        std::cout << "sub " + currOffsetReg.getRegId() + ", " + currOffsetReg.getRegId() + ", " +
                                     tempCurrOffsetReg.getRegId() << std::endl;

                        // Update currType
                        currType = recordType->lookupType(dotId);
                    } else {
                        throw std::runtime_error("ERROR: dot accessing can only be used on records");
                    }
                }
            }
        }

        // Emit
        std::cout << "lw " + currOffsetReg.getRegId() + ", (" + currOffsetReg.getRegId() + ")" << std::endl;

        return currOffsetReg;
    } else {
        auto reg = symbol->emitMips();
        return reg;
    }
}

RegisterPool::Register LValue::emitAddr() {
//    std::cout<<"BEG: " << registerPool.getAvailableCount() << std::endl;
    Symbol* symbol = getSymbol();

    // 1. Find address of first word
    Type* currType = symbol->getType();
    std::cout << "# LVal" << std::endl;
    auto currOffsetReg = registerPool.get();

    if (symbol->isRef) {
        std::cout << "lw " + currOffsetReg.getRegId() + ", " + std::to_string(lookupBaseOffset()) + "(" + lookupBase() + ")" << std::endl;
    } else {
        int currOffset = lookupBaseOffset();
        std::cout << "li " + currOffsetReg.getRegId() + ", " + std::to_string(currOffset) << std::endl;
        std::cout << "sub " + currOffsetReg.getRegId() + ", "  + lookupBase() + ", " + currOffsetReg.getRegId() << std::endl;
    }

    // Lookup lVal extensions
    if (exts != nullptr) {
        for (auto ext = exts->begin(); ext != exts->end(); ++ext) {
            auto indexExt = dynamic_cast<IndexExt*>((*ext));

            if (indexExt != nullptr) {
                // CASE: ARRAY
                if (currType->typeEnum == ARRAY_T) {
                    ArrayType* arrayType = dynamic_cast<ArrayType*>(currType);
                     const ConstExpr *lowIndex = dynamic_cast<const ConstExpr *>(arrayType->begin);

                    // 2. Compute indexing expression
                    Expr *indexExpr = const_cast<Expr *>(indexExt->a);

                    // 3. Find position of element (nth)
                    std::cout << "# Calc array index" << std::endl;
                    auto indexReg = Sub::emitMips(indexExpr, (Expr*)lowIndex);

                    // 4. Find offset from array base
                    // Load array element from size
                    auto elementSizeReg = registerPool.get();
                    int elementSize = arrayType->arrayType->size();
                    std::cout << "# Load element size" << std::endl;
                    std::cout << "li " + elementSizeReg.getRegId() + ", " + std::to_string(elementSize) << std::endl;
                    // Calculate offset
                    std::cout << "# Calculate array offset" << std::endl;
                    auto offsetReg = Mult::emitMips(indexReg, elementSizeReg);

                    // 5. Subtract offset from array base
                    std::cout << "# Sub offset to base" << std::endl;
                    currOffsetReg = Sub::emitMips(currOffsetReg, offsetReg);

                    // Update currType
                    currType = arrayType->arrayType;
                } else {
                    // ToDo: record errors and print in mips
                    throw std::runtime_error("ERROR: array indexing can only be used on arrays");
                }
            }

            auto dotExt = dynamic_cast<DotExt*>((*ext));

            if (dotExt != nullptr) {
                // CASE: RECORD
                if (currType->typeEnum == RECORD_T) {
                    auto* recordType = dynamic_cast<RecordType*>(currType);
                    std::string dotId = dotExt->id->id;
                    int currOffset = recordType->lookupOffset(dotId);

                    // Sub offset from reg
                    auto tempCurrOffsetReg = registerPool.get();
                    std::cout << "li " + tempCurrOffsetReg.getRegId() + ", " + std::to_string(currOffset) << std::endl;
                    currOffsetReg = Sub::emitMips(currOffsetReg, tempCurrOffsetReg);

                    // Update currType
                    currType = recordType->lookupType(dotId);
                } else {
                    throw std::runtime_error("ERROR: dot accessing can only be used on records");
                }
            }
        }
    }

//   std::cout<<"END: " << registerPool.getAvailableCount() << std::endl;
    return currOffsetReg;
}