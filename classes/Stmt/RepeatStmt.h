//
// Created by zion on 2/26/20.
//

#ifndef CPSL_COMPILER_REPEATSTMT_H
#define CPSL_COMPILER_REPEATSTMT_H

#include <List/StmtList.h>
#include <Expr/Expr.h>
#include "Stmt.h"

struct RepeatStmt: Stmt {
    const StmtList* stmts;
    const Expr* expr;

    RepeatStmt(StmtList*, Expr*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_REPEATSTMT_H