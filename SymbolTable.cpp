//
// Created by zion on 3/28/20.
//

#include <classes/Type/Primitive.h>
#include <classes/Expr/ConstExpr/BoolConstExpr.h>
#include <iostream>
#include "SymbolTable.h"

Symbol* SymbolTable::lookupSymbol(std::string id) {
    for (auto level = scopeLevels.rbegin(); level != scopeLevels.rend(); ++level) {
        auto symbol = level->lookupSymbol(id);
        if (symbol != nullptr) {
            return symbol;
        } else {
            return nullptr;
        }
    }
}

void SymbolTable::addSymbol(std::string id, Symbol* symbol) {
    auto& topScope = scopeLevels.back();
    topScope.addSymbol(id, symbol);
}

Type* SymbolTable::lookupType(std::string id) {
    for (auto level = scopeLevels.rbegin(); level != scopeLevels.rend(); ++level) {
        auto type = level->lookupType(id);
        if (type != nullptr) {
            return type;
        } else {
            return nullptr;
        }
    }
}

void SymbolTable::addType(std::string id, Type* type) {
    auto& topScope = scopeLevels.back();
    topScope.addType(id, type);
}

void SymbolTable::enterScope() {
    scopeLevels.push_back(Scope());
}

void SymbolTable::listSymbols() {
    int n_scopes = scopeLevels.size();
    int scope_count = 0;
    for (auto scope = scopeLevels.rbegin(); scope != scopeLevels.rend(); ++scope) {
        std::cout << "Scope " << n_scopes - scope_count << std::endl;
        scope->listSymbols();
    }
}

void SymbolTable::listTypes() {
    int n_scopes = scopeLevels.size();
    int scope_count = 0;
    for (auto scope = scopeLevels.rbegin(); scope != scopeLevels.rend(); ++scope) {
        std::cout << "Scope " << n_scopes - scope_count << std::endl;
        scope->listTypes();
    }
}

SymbolTable::SymbolTable() {
//    Enter scope
    this->enterScope();
//    Init predefined identifiers
    this->addType("integer", new Primitive());
    this->addType("char", new Primitive());
    this->addType("boolean", new Primitive());
    this->addType("string", new Primitive());

    Symbol* true_const = new Symbol(new BoolConstExpr(true));
    this->addSymbol("true", true_const);
    Symbol* false_const = new Symbol(new BoolConstExpr(false));
    this->addSymbol("false", false_const);
}