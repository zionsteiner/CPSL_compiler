//
// Created by zion on 3/9/20.
//

#include "Procedure.h"

// Forward decl
Procedure::Procedure(Ident* id, std::vector<Param*>* params)
        : id(id), params(params), forward(true), body(nullptr)
{}

// Procedure definition
Procedure::Procedure(Ident* id, std::vector<Param*>* params, Body* body)
        : id(id), params(params), forward(false), body(body)
{}

std::string Procedure::toString() const {
    std::string retStr = "Procedure";

    retStr = id->toString() + '(';
    if (params != nullptr) {
        for (auto param = params->begin(); param != params->end(); ++param) {
            retStr += ' ' + (*param)->toString();
        }
    }
    retStr += ')';
    if (forward) {
        retStr += " forward";
    } else {
        retStr += ' ' + body->toString();
    }
    retStr += ';';
}