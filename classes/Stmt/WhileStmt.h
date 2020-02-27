//
// Created by zion on 2/26/20.
//

#ifndef CPSL_COMPILER_WHILESTMT_H
#define CPSL_COMPILER_WHILESTMT_H

#include <Expr/Expr.h>
#include <List/StmtList.h>
#include "Stmt.h"

struct WhileStmt: Stmt {
    const Expr* expr;
    const StmtList* stmts;

    WhileStmt(Expr*, StmtList*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_WHILESTMT_H
