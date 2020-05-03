//
// Created by zion on 3/9/20.
//

#include <globals.h>
#include "Procedure.h"

// Forward decl
Procedure::Procedure(Ident* id, std::vector<Param*>* params): Callable(id, params) {}

// Procedure definition
Procedure::Procedure(Ident* id, std::vector<Param*>* params, Body* body): Callable(id, params, body) {}


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

    return retStr;
}

void Procedure::emitMips() {
    if (forward) {
        throw std::invalid_argument("Procedure " + id->toString() + " has not been defined");
    }

    std::cout << "# Procedure" << std::endl;
    std::cout << label + ":" << std::endl;

    if (body->constDecl != nullptr) {body->constDecl->emitMips();}
    if (body->typeDecl != nullptr) {body->typeDecl->emitMips();}
    if (body->varDecl != nullptr) {body->varDecl->emitMips();}
    for (auto stmt : *body->block->stmts) {
        stmt->emitMips();
    }
}

