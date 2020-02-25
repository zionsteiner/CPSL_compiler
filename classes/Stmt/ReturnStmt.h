//
// Created by zion on 2/24/20.
//

#ifndef CPSL_COMPILER_RETURNSTMT_H
#define CPSL_COMPILER_RETURNSTMT_H

#include <Expr/Expr.h>
#include "Stmt.h"

struct ReturnStmt: Stmt {
    const Expr* expr;

    ReturnStmt(Expr*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_RETURNSTMT_H
