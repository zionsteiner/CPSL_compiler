//
// Created by zion on 2/20/20.
//

#ifndef CPSL_COMPILER_VARDECLOPT_H
#define CPSL_COMPILER_VARDECLOPT_H

#include "Opt.h"
#include "classes/VarDecl.h"

struct VarDeclOpt: Opt {
    const VarDecl* varDecl;

    VarDeclOpt();
    VarDeclOpt(VarDecl*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_VARDECLOPT_H
