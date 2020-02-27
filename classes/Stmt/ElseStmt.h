//
// Created by zion on 2/26/20.
//

#ifndef CPSL_COMPILER_ELSESTMT_H
#define CPSL_COMPILER_ELSESTMT_H

#include <List/StmtList.h>
#include "Stmt.h"

struct ElseStmt: Stmt {
    const StmtList* stmts;

    ElseStmt(StmtList*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_ELSESTMT_H
