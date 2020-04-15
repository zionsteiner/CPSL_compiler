//
// Created by zion on 2/26/20.
//

#ifndef CPSL_COMPILER_REPEATSTMT_H
#define CPSL_COMPILER_REPEATSTMT_H

#include <vector>
#include "Stmt.h"
#include "../Expr/Expr.h"

struct RepeatStmt: Stmt {
    const std::vector<Stmt*>* stmts;
    Expr *expr;

    RepeatStmt(std::vector<Stmt*>*, Expr*);
    std::string toString() const override;
    void emitMips() override;
};


#endif //CPSL_COMPILER_REPEATSTMT_H