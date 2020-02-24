//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_IDLIST_H
#define CPSL_COMPILER_IDLIST_H

#include <vector>
#include <classes/Expr/Ident.h>
#include "List.h"

struct IdList: List {
    std::vector<Ident*> list;

    explicit IdList(Ident*);
    void append(Ident*);
    std::string toString() const override;
};

#endif //CPSL_COMPILER_IDLIST_H
