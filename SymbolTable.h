//
// Created by zion on 3/28/20.
//

#ifndef CPSL_COMPILER_SYMBOLTABLE_H
#define CPSL_COMPILER_SYMBOLTABLE_H


#include <classes/Expr/LValue/LValue.h>
#include <classes/Type/Type.h>
#include "Scope.h"

class SymbolTable {
public:
    LValue* lookupLVal(std::string);
    Type* lookupType(std::string);

private:
    std::vector<Scope> scopeLevels;
};


#endif //CPSL_COMPILER_SYMBOLTABLE_H
