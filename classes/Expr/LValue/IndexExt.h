//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_INDEXEXT_H
#define CPSL_COMPILER_INDEXEXT_H

#include "Ext.h"
#include "../Expr.h"

struct IndexExt: Ext {
    const Expr* a;

    explicit IndexExt(Expr*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_INDEXEXT_H
