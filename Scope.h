//
// Created by zion on 3/28/20.
//

#ifndef CPSL_COMPILER_SCOPE_H
#define CPSL_COMPILER_SCOPE_H


#include <classes/Type/Type.h>
#include <map>
#include <classes/Expr/LValue/LValue.h>

class Scope {
public:
    LValue* lookupLVal(std::string);
    Type* lookupType(std::string);
    void addType(Type*, std::string);
    void addLVal(Expr*, std::string);

private:
    std::map<std::string, LValue*> lVals;
    std::map<std::string, Type*> types;
};


#endif //CPSL_COMPILER_SCOPE_H
