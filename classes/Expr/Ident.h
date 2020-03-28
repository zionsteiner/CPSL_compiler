//
// Created by zion on 2/20/20.
//

#ifndef CPSL_COMPILER_IDENT_H
#define CPSL_COMPILER_IDENT_H

#include "Expr.h"

struct Ident: Expr {
    const std::string id;

    Ident(const char*);
    bool isCompVal() override;
    std::string toString() const override;
};


#endif //CPSL_COMPILER_IDENT_H
