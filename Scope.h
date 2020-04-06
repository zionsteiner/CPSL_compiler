//
// Created by zion on 3/28/20.
//

#ifndef CPSL_COMPILER_SCOPE_H
#define CPSL_COMPILER_SCOPE_H


#include <classes/Type/Type.h>
#include <map>
#include <classes/Expr/LValue/LValue.h>
#include "Symbol.h"

class Scope {
public:
    Symbol* lookupSymbol(std::string);
    Type* lookupType(std::string);
    void addType(std::string, Type*);
    void addSymbol(std::string, Symbol*);
    void listSymbols();
    void listTypes();
    int getNextOffset();
    std::string getBaseReg();
    Scope(std::string);

private:
    std::map<std::string, Symbol*> symbols;
    std::map<std::string, Type*> types;
    std::string baseReg;
    int nextOffset = 0;
};


#endif //CPSL_COMPILER_SCOPE_H
