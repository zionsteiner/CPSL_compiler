//
// Created by zion on 2/19/20.
//

#include <classes/Type/SimpleType.h>
#include <globals.h>
#include "VarAssign.h"

VarAssign::VarAssign(std::vector<Ident*>* idList, Type* type): idList(idList), type(type) {
    // Add all ids to table
    for (auto id = idList->begin(); id != idList->end(); ++id) {
        int offset = symbolTable.getNextOffset();
        Symbol* varSymbol = new Symbol(offset, type);
        symbolTable.addSymbol((*id)->id, varSymbol);
    }
}

std::string VarAssign::toString() const {
    std::string retStr;
    retStr += (*idList)[0]->toString();
    for (auto id = idList->begin() + 1; id != idList->end(); ++id) {
        retStr += ", " + (*id)->toString();
    }
    retStr += " : " + type->toString() + ';';

    return retStr;
}

VarAssign::~VarAssign() {}
