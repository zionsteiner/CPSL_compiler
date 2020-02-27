//
// Created by zion on 2/24/20.
//

#ifndef CPSL_COMPILER_WRITESTMT_H
#define CPSL_COMPILER_WRITESTMT_H

#include <List/ExprList.h>
#include "Stmt.h"

struct WriteStmt: Stmt {
    const ExprList<Expr*>* args;

    explicit WriteStmt(ExprList<Expr *> *args);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_WRITESTMT_H
