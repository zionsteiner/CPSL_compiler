//
// Created by zion on 2/20/20.
//

#include <Symbol.h>
#include <globals.h>
#include <classes/Type/ArrayType.h>
#include "VarDecl.h"

VarDecl::VarDecl(std::vector<VarAssign*>* varAssignList): varAssignList(varAssignList) {}
std::string VarDecl::toString() const {
    std::string retStr = "VAR";
    for (auto varAssign = varAssignList->begin(); varAssign != varAssignList->end(); ++varAssign) {
        retStr += "\n\t" + (*varAssign)->toString();
    }

    return retStr;
}

void VarDecl::emitMips() {
    for (auto varAssign = varAssignList->begin(); varAssign != varAssignList->end(); ++varAssign) {
        auto idList = (*varAssign)->idList;
        Type* type = (*varAssign)->type;

        // Add all ids to table and emit
        for (auto id = idList->begin(); id != idList->end(); ++id) {
            int offset = symbolTable.getNextOffset();
            Symbol* varSymbol = new Symbol(offset, type);
            symbolTable.addSymbol((*id)->id, varSymbol);
        }
    }
}