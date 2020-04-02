//
// Created by zion on 3/12/20.
//

#include "TypeDecl.h"

TypeDecl::TypeDecl(std::vector<TypeAssign*>* typeAssignPlus): typeAssignPlus(typeAssignPlus) {}
std::string TypeDecl::toString() const {
    std::string retStr = "TYPE";
    for (auto typeAssign = typeAssignPlus->begin(); typeAssign != typeAssignPlus->end(); ++typeAssign) {
        retStr += "\n\t" + (*typeAssign)->toString();
    }

    return retStr;
}
