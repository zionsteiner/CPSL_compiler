//
// Created by zion on 2/18/20.
//

#include <vector>
#include <iostream>
#include "idList.h"

idList::idList() {}

void idList::append(char* cStr) {
    std::string str(cStr);
    list.push_back(Str);
}

std::string idList::toString() const {
    std::string retStr = list[0];
    for (auto str = list.begin() + 1; str != list.end(); ++str) {
        retStr += ", " + *str;
    }

    return retStr;
}