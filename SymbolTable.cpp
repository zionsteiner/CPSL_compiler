//
// Created by zion on 3/28/20.
//

#include <classes/Type/Primitive.h>
#include <classes/Expr/ConstExpr/BoolConstExpr.h>
#include <classes/Expr/LValue/LValue.h>
#include "SymbolTable.h"
#include "globals.h"

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

void SymbolTable::saveState() {
    Scope topScope = scopeLevels.back();
    topScope.saveState();
}

void SymbolTable::enterScope() {
    int offset = 0;
    if (scopeLevels.size() > 1) {
        offset = getNextOffset();
    }
    Scope newScope = Scope(offset);
    scopeLevels.emplace_back(newScope);

    for (auto entry : argStorage) {
        newScope.loadArg(entry.first, entry.second);
    }
}

void SymbolTable::exitScope() {
    // Pop stack
    scopeLevels.pop_back();
    auto topScope = scopeLevels.back();

    // Clear function args from stack
    int totalArgOffset = 0;
    for (auto entry : argStorage) {
        auto symbol = entry.second;
        if (symbol->isRef) {
            totalArgOffset += 4;
        } else {
            totalArgOffset += symbol->type->size();
        }
    }
    std::cout << "addi $sp, $sp, " + std::to_string(totalArgOffset) << std::endl;

    // Reset scope state
    topScope.resetState();
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
    this->enterScope();
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

int SymbolTable::getFpOffset() {
    Scope topScope = scopeLevels.back();
    return topScope.getScopeOffset();
}



void SymbolTable::loadArg(std::string argId, Expr* arg, Param* param) {
    if (param->isPassByRef) {
        auto lVal = dynamic_cast<LValue*>(arg);

        if (lVal == nullptr) {
            throw std::invalid_argument("Cannot pass non lval by ref");
        }

        std::cout << "addi $sp, $sp, -4" << std::endl;
        auto symbol = new Symbol(symbolTable.getNextOffset(), param->type, true);
        argStorage[argId] = symbol;
        symbolTable.incrOffset(-4);
        auto refAddrReg = lVal->emitAddr();
        std::cout << "sw " + refAddrReg.getRegId() + ", 0($sp)" << std::endl;
    } else {
        auto type = param->type;

        // Make room on stack for arg
        int assnSize = type->size();
        auto initCopyAddrReg = registerPool.get();
        std::cout << "la " + initCopyAddrReg.getRegId() + ", " + "($sp)" << std::endl;
        std::cout << "addi $sp, $sp, " + std::to_string(assnSize) << std::endl;
        auto symbol = new Symbol(symbolTable.getNextOffset(), param->type);
        argStorage[argId] = symbol;
        symbolTable.incrOffset(-assnSize);

        // Copy arg
        auto assnLVal = dynamic_cast<LValue*>(arg);
        if (assnLVal != nullptr) {
            if (type->typeEnum == ARRAY_T) {
                std::cout << "# Copy array" << std::endl;

                // Get base address
                auto assnLValAddrReg = assnLVal->emitAddr();

                // Copy
                for (int i = 0; i < assnSize; i += 4) {
                    auto copyReg = registerPool.get();
                    std::cout << "lw " + copyReg.getRegId() + ", " + std::to_string(-i) + "(" + assnLValAddrReg.getRegId() + ")" << std::endl;
                    std::cout << "sw " + copyReg.getRegId() + ", " + std::to_string(-i) + "(" + initCopyAddrReg.getRegId() + ")" << std::endl;
                }
            } else if (type->typeEnum == RECORD_T) {
                std::cout << "# Copy record" << std::endl;

                // Get base address
                auto assnLValAddrReg = assnLVal->emitAddr();

                // Copy
                auto copyReg = registerPool.get();
                for (int i = 0; i < assnSize; i += 4) {
                    std::cout << "lw " + copyReg.getRegId() + ", " + std::to_string(-i) + "(" + assnLValAddrReg.getRegId() + ")" << std::endl;
                    std::cout << "sw " + copyReg.getRegId() + ", " + std::to_string(-i) + "(" + initCopyAddrReg.getRegId() + ")" << std::endl;
                }
            } else {
                auto reg = assnLVal->emitMips();
                std::cout << "sw " + reg.getRegId() + ", (" + initCopyAddrReg.getRegId() + ")" << std::endl;
            }
        } else {
            auto reg = arg->emitMips();
            std::cout << "sw " + reg.getRegId() + ", (" + initCopyAddrReg.getRegId() + ")" << std::endl;
        }
    }
}

void SymbolTable::incrOffset(int incr) {
    Scope topScope = scopeLevels.back();
    topScope.incrOffset(incr);
}
