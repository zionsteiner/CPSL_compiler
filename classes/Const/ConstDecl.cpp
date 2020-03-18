//
// Created by zion on 3/9/20.
//

#include "ConstDecl.h"

ConstDecl::ConstDecl(std::vector<ConstAssign*>* constAssignList): constAssignList(constAssignList) {}
std::string ConstDecl::toString() const {
    std::string retStr = "const " + (*constAssignList)[0];
    if (constAssignList->size() > 1) {
        for (auto constAssign = constAssignList->begin() + 1; constAssign != constAssignList->end(); ++constAssign) {
            retStr += ' ' + (*constAssign)->toString();
        }
    }

    return retStr;
}