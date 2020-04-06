//
// Created by zion on 3/12/20.
//

#include <globals.h>
#include "TypeDecl.h"
#include "SimpleType.h"

TypeDecl::TypeDecl(std::vector<TypeAssign*>* typeAssignPlus): typeAssignPlus(typeAssignPlus) {}
std::string TypeDecl::toString() const {
    std::string retStr = "TYPE";
    for (auto typeAssign = typeAssignPlus->begin(); typeAssign != typeAssignPlus->end(); ++typeAssign) {
        retStr += "\n\t" + (*typeAssign)->toString();
    }

    return retStr;
}

void TypeDecl::emitMips() {
    for (auto typeAssign = typeAssignPlus->begin(); typeAssign != typeAssignPlus->end(); ++typeAssign) {
        Type* type = const_cast<Type*>((*typeAssign)->type);

        // If SimpleType, redirect type reference
        SimpleType* s_type = dynamic_cast<SimpleType*>(type);
        if (s_type != nullptr) {
            type = symbolTable.lookupType(s_type->id->id);
            symbolTable.addType((*typeAssign)->id->id, type);
        } else {
            symbolTable.addType((*typeAssign)->id->id, type);
        }
    }
}
