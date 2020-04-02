//
// Created by zion on 3/28/20.
//

#include "Scope.h"

LValue* Scope::lookupLVal(std::string key) {
    auto lVal = lVals.find(key);
    if (lVal != lVals.end()) {
        return lVal->second;
    } else {
        return nullptr;
    }
}

Type * Scope::lookupType(std::string key) {
    auto type = types.find(key);
    if (type != types.end()) {
        return type->second;
    } else {
        return nullptr;
    }
}

void Scope::addLVal(Expr* expr, std::string key) {
    lVals[key] = expr;
}

void Scope::addType(Type* type, std::string key) {
    types[key] = type;
}