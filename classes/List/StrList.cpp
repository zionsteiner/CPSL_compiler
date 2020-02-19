//
// Created by zion on 2/18/20.
//

#include "StrList.h"

StrList::StrList(char* cStr) {
    std::string str(cStr);
    list.push_back(str);
}

StrList::append(char* cStr) {
    std::string str(cStr);
    list.push_back(Str);
}

StrList::toString() {
    for (std::vector<std::string>::iterator str = list.begin(); str != list.end(); ++str) {
        std::cout << str << ' ';
    }
}