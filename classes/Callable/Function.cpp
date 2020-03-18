//
// Created by zion on 3/9/20.
//

#include "Function.h"

// Forward decl
Function::Function(Ident* id, std::vector<Param*>* params, Type* type)
: id(id), params(params), type(type), forward(true), body(nullptr)
{}

// Function definition
Function::Function(Ident* id, std::vector<Param*>* params, Type* type, Body* body)
: id(id), params(params), type(type), forward(false), body(body)
{}

std::string Function::toString() const {
    std::string retStr += 'function';

    retStr = id->toString() + '(';
    if (params != nullptr) {
        for (auto param = params->begin(); param != params->end(); ++param) {
            retStr += ' ' + (*param)->toString();
        }
    }
    retStr += '):';
    retStr += ' ' + type->toString();
    if (forward) {
        retStr += ' forward';
    } else {
        retStr += ' ' + body->toString();
    }
    retStr += ';';
}