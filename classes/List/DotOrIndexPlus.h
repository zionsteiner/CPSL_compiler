//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_DOTORINDEXPLUS_H
#define CPSL_COMPILER_DOTORINDEXPLUS_H

#include <Expr/LValue/Ext.h>
#include <vector>
#include "List.h"

struct DotOrIndexPlus: List {
    std::vector<Ext*> list;

    explicit DotOrIndexPlus(Ext*);
    void append(Ext*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_DOTORINDEXPLUS_H
