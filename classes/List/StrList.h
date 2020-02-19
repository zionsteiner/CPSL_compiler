//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_STRLIST_H
#define CPSL_COMPILER_STRLIST_H

#include <vector>
#include "List.h"

struct StrList: List {
    std::vector<std::string> list;

    StrList(char*);
    void append(char*);
    void toString();
};

#endif //CPSL_COMPILER_STRLIST_H
