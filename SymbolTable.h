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
    int getNextOffset();
    std::string getCurrBaseReg();
    std::string getBaseRegById(std::string);
    std::string addString(std::string);
    std::map<std::string, std::string>* getStrings();
    SymbolTable();

private:
    std::vector<Scope> scopeLevels;
    std::map<std::string, std::string> strings;
};


#endif //CPSL_COMPILER_SYMBOLTABLE_H
