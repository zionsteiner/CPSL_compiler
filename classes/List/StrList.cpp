//
// Created by zion on 2/18/20.
//

#include <vector>
#include <iostream>
#include "StrList.h"

StrList::StrList(char* cStr) {
    std::string str(cStr);
    list.push_back(str);
}

StrList::append(char* cStr) {
    std::string str(cStr);
    list.push_back(Str);
}

void StrList::toString() {
    std::cout << list[0];
    for (std::vector<char*>::iterator str = list.begin() + 1; str != list.end(); ++str) {
        std::cout << ', ' + str.toString();
    }
}