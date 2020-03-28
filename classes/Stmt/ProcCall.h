//
// Created by zion on 2/24/20.
//

#ifndef CPSL_COMPILER_PROCCALL_H
#define CPSL_COMPILER_PROCCALL_H

#include <vector>
#include "classes/Stmt/Stmt.h"
#include "classes/Expr/Ident.h"

struct ProcCall: Stmt {
    const Ident* id;
    const std::vector<Expr*>* args;

    ProcCall(Ident*, std::vector<Expr*>*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_PROCCALL_H
