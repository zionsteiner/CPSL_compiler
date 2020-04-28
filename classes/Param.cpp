//
// Created by zion on 2/19/20.
//

#include "Param.h"

Param::Param(bool isPassByRef, std::vector<Ident*>* idList, Type* type): isPassByRef(isPassByRef), idList(idList), type(type) {}
std::string Param::toString() const {
    std::string retStr = (isPassByRef) ? "ref" : "var";
    retStr += ' ' + (*idList)[0]->toString();

    if (idList->size() > 1) {
        for (auto id : *idList) {
            retStr += ' ' + id->toString();
        }
    }

    return retStr;
}