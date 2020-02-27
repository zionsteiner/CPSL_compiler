//
// Created by zion on 2/27/20.
//

#ifndef CPSL_COMPILER_IFSTMT_H
#define CPSL_COMPILER_IFSTMT_H

#include <Expr/Expr.h>
#include <List/StmtList.h>
#include <List/ElseIfStmtList.h>
#include "Stmt.h"
#include "ElseStmt.h"

struct IfStmt: Stmt {
    const Expr* condition;
    const StmtList* stmts;
    const ElseIfStmtList* elseIfStmts;
    const ElseStmt* elseStmt;

    IfStmt(Expr*, StmtList*, ElseIfStmtList*, ElseStmt*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_IFSTMT_H
