//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_DOTEXT_H
#define CPSL_COMPILER_DOTEXT_H


#include <Expr/Ident.h>
#include "Ext.h"

struct DotExt: Ext {
    const Ident* id;

    explicit DotExt(Ident*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_DOTEXT_H
