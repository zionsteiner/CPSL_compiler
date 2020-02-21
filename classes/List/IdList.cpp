//
// Created by zion on 2/18/20.
//

#include <vector>
#include <iostream>
#include "IdList.h"

IdList::IdList() = default;

void IdList::append(Ident* id) {
    list.push_back(id);
}

std::string IdList::toString() const {
    std::string retStr = list[0]->toString();
    for (auto str = list.begin() + 1; str != list.end(); ++str) {
        retStr += ", " + (*str)->toString();
    }

    return retStr;
}