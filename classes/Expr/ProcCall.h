//
// Created by zion on 2/24/20.
//

#ifndef CPSL_COMPILER_PROCCALL_H
#define CPSL_COMPILER_PROCCALL_H

#include <List/ExprList.h>
#include "Expr.h"
#include "Ident.h"

struct ProcCall: Expr {
    const Ident* id;
    const ExprList* args;

    ProcCall(Ident*, ExprList*);
    bool isCompVal() override;
    std::string toString() const override;
};


#endif //CPSL_COMPILER_PROCCALL_H
