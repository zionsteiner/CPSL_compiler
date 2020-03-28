//
// Created by zion on 2/27/20.
//

#ifndef CPSL_COMPILER_IFSTMT_H
#define CPSL_COMPILER_IFSTMT_H

#include "Stmt.h"
#include "ElseStmt.h"
#include "ElseIfStmt.h"

struct IfStmt: Stmt {
    const Expr* condition;
    const std::vector<Stmt*>* stmts;
    const std::vector<ElseIfStmt*>* elseIfStmts;
    const ElseStmt* elseStmt;

    IfStmt(Expr*, std::vector<Stmt*>*, std::vector<ElseIfStmt*>*, ElseStmt*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_IFSTMT_H
