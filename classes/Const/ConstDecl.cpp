//
// Created by zion on 3/9/20.
//

#include "ConstDecl.h"

ConstDecl::ConstDecl(std::vector<ConstAssign*>* constAssignList): constAssignList(constAssignList) {}
std::string ConstDecl::toString() const {
    std::string retStr = "CONST";
    for (auto constAssign = constAssignList->begin(); constAssign != constAssignList->end(); ++constAssign) {
        retStr += "\n\t" + (*constAssign)->toString();
    }

    return retStr;
}

std::string ConstDecl::emitMips() {
    std::string mips;
}