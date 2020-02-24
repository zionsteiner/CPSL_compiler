//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_INDEXEXT_H
#define CPSL_COMPILER_INDEXEXT_H

#include <Expr/Expr.h>
#include "Ext.h"

struct IndexExt: Ext {
    const Expr* a;

    explicit IndexExt(Expr*);
    std::string IndexExt::toString() const override;
};


#endif //CPSL_COMPILER_INDEXEXT_H
