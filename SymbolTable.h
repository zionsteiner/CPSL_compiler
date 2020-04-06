//
// Created by zion on 3/28/20.
//

#ifndef CPSL_COMPILER_SYMBOLTABLE_H
#define CPSL_COMPILER_SYMBOLTABLE_H


#include <classes/Type/Type.h>
#include "Scope.h"

class SymbolTable {
public:
    Symbol* lookupSymbol(std::string);
    void addSymbol(std::string, Symbol*);
    Type* lookupType(std::string);
    void addType(std::string, Type*);
    void enterScope();
    void listSymbols();
    void listTypes();
    SymbolTable();

private:
    std::vector<Scope> scopeLevels;
};


#endif //CPSL_COMPILER_SYMBOLTABLE_H
