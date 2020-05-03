//
// Created by zion on 3/28/20.
//

#include <iostream>
#include "Scope.h"
#include "Symbol.h"
#include "globals.h"

Scope::Scope(int offset) {
    this->baseReg = "$fp";
    this->scopeOffset = offset;
}

Symbol* Scope::lookupSymbol(std::string key) {
    auto symbol = symbols.find(key);
    if (symbol != symbols.end()) {
        return symbol->second;
    } else {
        return nullptr;
    }
}

Type* Scope::lookupType(std::string key) {
    auto type = types.find(key);
    if (type != types.end()) {
        return type->second;
    } else {
        return nullptr;
    }
}

void Scope::addSymbol(std::string key, Symbol* symbol) {
    symbol->base = symbolTable.getCurrBaseReg();
    symbols[key] = symbol;
    if (symbol->offset != -1) {
        if (symbol->offset == nextOffset) {
            nextOffset -= symbol->type->size();
        } else {
            throw "ERROR: Invalid symbol offset";
        }
    }
}

void Scope::addType(std::string key, Type* type) {
    types[key] = type;
}

void Scope::listSymbols() {
    for (auto symbol = symbols.begin(); symbol != symbols.end(); ++symbol) {
        std::cout << "ID: " << symbol->first << std::endl;
        if (symbol->second->offset == -1) {
            std::cout << "Text: " << symbol->second->expr->toString() << std::endl;
        } else {
            std::cout << "Text: " << "unknown" << std::endl;
        }
        std::cout << "Type: " << symbol->second->type->toString() << std::endl;
    }
}

void Scope::listTypes() {
    for (auto type = types.begin(); type != types.end(); ++type) {
        std::cout << "ID: " << type->first << std::endl;
        std::cout << "Text: " << type->second->toString() << std::endl;
    }
}

int Scope::getNextOffset() {return nextOffset;}
std::string Scope::getBaseReg() {return baseReg;}

void Scope::removeSymbol(std::string id) {
    symbols.erase(id);
}

void Scope::saveState() {
    // Save regpool state
    availableRegState = registerPool.getAvailableRegs();
    usedRegState = registerPool.getUsedRegs();

    // Spill regs
    int currOffset = 0;
    int regSpillOffset = 4 * (usedRegState.size() + 2);
    std::cout << "addi $sp, $sp, -" + std::to_string(regSpillOffset) << std::endl;

    for (auto reg : usedRegState) {
        std::cout << "sw " + reg + ", " + std::to_string(regSpillOffset) + "($sp)" << std::endl;
        regSpillAddrs[reg] = currOffset;
        currOffset += 4;
    }
    // Save $ra and $fp
    std::cout << "sw $ra, " + std::to_string(currOffset) + "($sp)" << std::endl;
    currOffset += 4;
    std::cout << "sw $fp, " + std::to_string(currOffset) + "($sp)" << std::endl;
}
