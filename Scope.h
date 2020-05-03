//
// Created by zion on 3/28/20.
//

#ifndef CPSL_COMPILER_SCOPE_H
#define CPSL_COMPILER_SCOPE_H


#include <classes/Type/Type.h>
#include <map>
#include "Symbol.h"

class Scope {
public:
    Symbol* lookupSymbol(std::string);
    Type* lookupType(std::string);

    void addSymbol(std::string, Symbol*);
    void addType(std::string, Type*);

    void removeSymbol(std::string);

    void listSymbols();
    void listTypes();

    int getNextOffset();
    std::string getBaseReg();

    void saveState();

    explicit Scope(int);

private:
    std::map<std::string, Symbol*> symbols;
    std::map<std::string, Type*> types;
    std::string baseReg;
    int scopeOffset;
    int nextOffset = 0;

    std::map<std::string, int> regSpillAddrs;
    std::vector<std::string> availableRegState;
    std::vector<std::string> usedRegState;
};


#endif //CPSL_COMPILER_SCOPE_H
