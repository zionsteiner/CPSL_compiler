//
// Created by zion on 3/28/20.
//

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

    auto s_type = dynamic_cast<SimpleType*>(symbol->type);
    if (s_type != nullptr) {
        symbol->type = symbolTable.lookupType(s_type->id->id);
    }

    topScope.addSymbol(std::move(id), symbol);
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
    topScope.addType(std::move(id), type);
}

void SymbolTable::enterScope(std::string base) {
    scopeLevels.push_back(Scope(base));
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

int SymbolTable::getNextOffset() {
    Scope topLevel = scopeLevels.back();
    return topLevel.getNextOffset();
}

std::string SymbolTable::getCurrBaseReg() {
    Scope topLevel = scopeLevels.back();
    return topLevel.getBaseReg();
}

std::string SymbolTable::getBaseRegById(std::string id) {
    for (auto scope = scopeLevels.rbegin(); scope != scopeLevels.rend(); ++scope) {
        auto symbol = scope->lookupSymbol(id);
        if (symbol != nullptr) {
            return scope->getBaseReg();
        } else {
            throw std::runtime_error("Symbol not found in table");
        }
    }
}

std::string SymbolTable::addString(std::string s) {
    int n = strings.size() + 1;
    std::string strId = "str" + std::to_string(n);
    strings[strId] = s;

    return strId;
}

std::map<std::string, std::string>* SymbolTable::getStrings() {return &strings;}

SymbolTable::SymbolTable() {
//    Enter scope
    this->enterScope("$gp");
//    Init predefined identifiers
    Type* intType = new Primitive(INT_T);
    this->addType("integer", intType);
    this->addType("INTEGER", intType);
    Type* chrType = new Primitive(CHR_T);
    this->addType("char", chrType);
    this->addType("CHAR", chrType);
    Type* boolType = new Primitive(BOOL_T);
    this->addType("boolean", boolType);
    this->addType("BOOLEAN", boolType);
    Type* strType = new Primitive(STR_T);
    this->addType("string", strType);
    this->addType("STRING", strType);

    Symbol* true_const = new Symbol(new BoolConstExpr(true), boolType);
    this->addSymbol("true", true_const);
    Symbol* false_const = new Symbol(new BoolConstExpr(false), boolType);
    this->addSymbol("false", false_const);
}

std::string SymbolTable::getNextLabel() {
    std::string label = "l" + std::to_string(labelCount);
    labelCount++;

    return label;
}

void SymbolTable::removeSymbol(std::string id) {
    for (auto level = scopeLevels.rbegin(); level != scopeLevels.rend(); ++level) {
        auto symbol = level->lookupSymbol(id);
        if (symbol != nullptr) {
            level->removeSymbol(id);
            break;
        }
    }
}

Callable *SymbolTable::lookupCallable(std::string sig) {
     auto callable = callables.find(sig);
     if (callable != callables.end()) {
         return callable->second;
     } else {
         return nullptr;
     }
}

void SymbolTable::addCallable(std::string sig, Callable* callable) {
    callables[sig] = callable;
}
