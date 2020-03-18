//
// Created by zion on 2/27/20.
//

#ifndef CPSL_COMPILER_ASSNSTMT_H
#define CPSL_COMPILER_ASSNSTMT_H

#include <Expr/Expr.h>
#include <Expr/LValue/LValue.h>
#include "Stmt.h"

struct AssnStmt: Stmt {
    const LValue* lVal;
    const Expr* expr;

    AssnStmt(LValue*, Expr*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_ASSNSTMT_H