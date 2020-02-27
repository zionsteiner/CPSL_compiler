//
// Created by zion on 2/26/20.
//

#ifndef CPSL_COMPILER_FORSTMT_H
#define CPSL_COMPILER_FORSTMT_H

#include <Expr/Expr.h>
#include <Expr/Ident.h>
#include <List/StmtList.h>
#include "Stmt.h"

struct ForStmt: Stmt {
    const Ident* id;
    const Expr* from;
    const std::string iterDirection;
    const Expr* to;
    const StmtList* stmts;

    ForStmt(Ident*, Expr*, std::string, Expr*, StmtList*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_FORSTMT_H
