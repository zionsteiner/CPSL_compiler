//
// Created by zion on 2/24/20.
//

#ifndef CPSL_COMPILER_WRITESTMT_H
#define CPSL_COMPILER_WRITESTMT_H

#include "Stmt.h"

struct WriteStmt: Stmt {
    const std::vector<Expr*>* args;

    explicit WriteStmt(std::vector<Expr*>* args);
    std::string toString() const override;
    void emitMips() override;
};


#endif //CPSL_COMPILER_WRITESTMT_H
