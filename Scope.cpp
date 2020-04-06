//
// Created by zion on 3/28/20.
//

#include <iostream>
#include "Scope.h"
#include "Symbol.h"

Symbol* Scope::lookupSymbol(std::string key) {
    auto symbol = symbols.find(key);
    if (symbol != symbols.end()) {
        return symbol->second;
    } else {
        return nullptr;
    }
}

Type * Scope::lookupType(std::string key) {
    auto type = types.find(key);
    if (type != types.end()) {
        return type->second;
    } else {
        return nullptr;
    }
}

void Scope::addSymbol(std::string key, Symbol* symbol) {
    symbols[key] = symbol;

}

void Scope::addType(std::string key, Type* type) {
    types[key] = type;
}

void Scope::listSymbols() {
    for (auto symbol = symbols.begin(); symbol != symbols.end(); ++symbol) {
        std::cout << "ID: " << symbol->first << std::endl;
        std::cout << "Text: " << symbol->second->expr->toString() << std::endl;
    }
}

void Scope::listTypes() {
    for (auto type = types.begin(); type != types.end(); ++type) {
        std::cout << "ID: " << type->first << std::endl;
        std::cout << "Text: " << type->second->toString() << std::endl;
    }
}