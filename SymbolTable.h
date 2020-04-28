//
// Created by zion on 3/28/20.
//

#ifndef CPSL_COMPILER_SYMBOLTABLE_H
#define CPSL_COMPILER_SYMBOLTABLE_H


#include <classes/Type/Type.h>
#include <classes/Callable/Callable.h>
#include <classes/Type/Primitive.h>
#include <classes/Expr/ConstExpr/BoolConstExpr.h>
#include <iostream>
#include <utility>
#include <classes/Type/SimpleType.h>
#include "Symbol.h"
#include "SymbolTable.h"
#include "Scope.h"

class SymbolTable {
public:
    Symbol* lookupSymbol(std::string);
    Type* lookupType(std::string);
    Callable* lookupCallable(std::string);

    void addSymbol(std::string, Symbol*);
    void addType(std::string, Type*);
    void addCallable(std::string, Callable*);
    std::string addString(std::string);

    void removeSymbol(std::string);

    void enterScope(std::string);

    void listSymbols();
    void listTypes();

    int getNextOffset();
    std::string getCurrBaseReg();
    std::string getBaseRegById(std::string);
    std::string getNextLabel();
    std::map<std::string, std::string>* getStrings();

    SymbolTable();

private:
    std::vector<Scope> scopeLevels;
    std::map<std::string, Callable*> callables;
    std::map<std::string, std::string> strings;
    int labelCount = 0;
};


#endif //CPSL_COMPILER_SYMBOLTABLE_H
