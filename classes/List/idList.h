//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_IDLIST_H
#define CPSL_COMPILER_IDLIST_H

#include <vector>
#include "List.h"

struct idList: List {
    std::vector<std::string> list;

    idList();
    void append(char*);
    std::string toString() const override;
};

#endif //CPSL_COMPILER_IDLIST_H
