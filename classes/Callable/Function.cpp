//
// Created by zion on 3/9/20.
//

#include <globals.h>
#include "Function.h"

// Forward decl
Function::Function(Ident* id, std::vector<Param*>* params, Type* type): Callable(id, params), type(type) {}

// Function definition
Function::Function(Ident* id, std::vector<Param*>* params, Type* type, Body* body): Callable(id, params, body), type(type) {}

std::string Function::toString() const {
    std::string retStr = "function";

    retStr = id->toString() + '(';
    if (params != nullptr) {
        for (auto param : *params) {
            retStr += ' ' + param->toString();
        }
    }
    retStr += "):";
    retStr += ' ' + type->toString();
    if (forward) {
        retStr += " forward";
    } else {
        retStr += ' ' + body->toString();
    }
    retStr += ';';

    return retStr;
}

void Function::emitMips() {}
