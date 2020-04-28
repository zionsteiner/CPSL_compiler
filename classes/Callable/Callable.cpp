//
// Created by zion on 4/27/20.
//

#include "Callable.h"

Callable::Callable(Ident *id, std::vector<Param*> *params, Body *body): id(id), params(params), forward(false), body(body) {
    std::string sig = id->toString() + "(";
    for (auto param : *params) {
        Type* type = param->type;
        for (auto argId : *param->idList) {
            if (type->typeEnum == SIMPLE_T) {
                auto s_type = dynamic_cast<SimpleType*>(type);
                type = symbolTable.lookupType(s_type->id->id);
            }
            sig += " " + std::to_string(type->typeEnum);
        }
    }
    sig += ")";

    label =  symbolTable.getNextLabel();
    symbolTable.addCallable(sig, this);
}

Callable::Callable(Ident *id, std::vector<Param *> *params): id(id), params(params), forward(true), body(nullptr) {
    std::string sig = id->toString() + "(";
    for (auto param : *params) {
        Type* type = param->type;
        for (auto argId : *param->idList) {
            if (type->typeEnum == SIMPLE_T) {
                auto s_type = dynamic_cast<SimpleType*>(type);
                type = symbolTable.lookupType(s_type->id->id);
            }
            sig += " " + std::to_string(type->typeEnum);
        }
    }
    sig += ")";

    label = symbolTable.getNextLabel();
    symbolTable.addCallable(sig, this);
}

Callable::~Callable() = default;
