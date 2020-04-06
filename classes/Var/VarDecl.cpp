//
// Created by zion on 2/20/20.
//

#include "VarDecl.h"

VarDecl::VarDecl(std::vector<VarAssign*>* varAssignList): varAssignList(varAssignList) {}
std::string VarDecl::toString() const {
    std::string retStr = "VAR";
    for (auto varAssign = varAssignList->begin(); varAssign != varAssignList->end(); ++ varAssign) {
        retStr += "\n\t" + (*varAssign)->toString();
    }

    return retStr;
}

void VarDecl::emitMips() {

}