//
// Created by zion on 2/26/20.
//

#ifndef CPSL_COMPILER_ELSEIFSTMT_H
#define CPSL_COMPILER_ELSEIFSTMT_H

#include <Expr/Expr.h>
#include <List/StmtList.h>
#include "Stmt.h"

struct ElseIfStmt: Stmt {
    const Expr* expr;
    const StmtList* stmts;

    ElseIfStmt(Expr*, StmtList*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_ELSEIFSTMT_H
