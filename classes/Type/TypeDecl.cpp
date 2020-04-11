//
// Created by zion on 3/12/20.
//

#include <globals.h>
#include "TypeDecl.h"

TypeDecl::TypeDecl(std::vector<TypeAssign*>* typeAssignPlus): typeAssignPlus(typeAssignPlus) {
    for (auto typeAssign = typeAssignPlus->begin(); typeAssign != typeAssignPlus->end(); ++typeAssign) {
        Type* type = const_cast<Type*>((*typeAssign)->type);
        symbolTable.addType((*typeAssign)->id->id, type);
    }
}
std::string TypeDecl::toString() const {
    std::string retStr = "TYPE";
    for (auto typeAssign = typeAssignPlus->begin(); typeAssign != typeAssignPlus->end(); ++typeAssign) {
        retStr += "\n\t" + (*typeAssign)->toString();
    }

    return retStr;
}

void TypeDecl::emitMips() {}
