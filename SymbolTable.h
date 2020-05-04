//
// Created by zion on 3/28/20.
//

#ifndef CPSL_COMPILER_SYMBOLTABLE_H
#define CPSL_COMPILER_SYMBOLTABLE_H


#include <classes/Callable/Callable.h>
#include "Scope.h"
#include "Symbol.h"

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

    void enterScope();
    void loadArg(std::string, Expr*, Param*);
    void saveState();
    void exitScope();

    void listSymbols();
    void listTypes();

    int getNextOffset();
    void incrOffset(int);
    std::string getCurrBaseReg();
    std::string getBaseRegById(std::string);
    std::string getNextLabel();
    int getFpOffset();
    std::map<std::string, std::string>* getStrings();

    SymbolTable();

private:
    std::vector<Scope> scopeLevels;
    std::map<std::string, Callable*> callables;
    std::map<std::string, std::string> strings;
    std::map<std::string, Symbol*> argStorage;
    int labelCount = 0;
};


#endif //CPSL_COMPILER_SYMBOLTABLE_H
