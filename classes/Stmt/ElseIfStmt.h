//
// Created by zion on 2/26/20.
//

#ifndef CPSL_COMPILER_ELSEIFSTMT_H
#define CPSL_COMPILER_ELSEIFSTMT_H

#include <vector>
#include "Stmt.h"
#include "../Expr/Expr.h"

struct ElseIfStmt: Stmt {
    const Expr* expr;
    const std::vector<Stmt*>* stmts;

    ElseIfStmt(Expr*, std::vector<Stmt*>*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_ELSEIFSTMT_H
