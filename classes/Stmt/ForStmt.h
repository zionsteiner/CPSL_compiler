//
// Created by zion on 2/26/20.
//

#ifndef CPSL_COMPILER_FORSTMT_H
#define CPSL_COMPILER_FORSTMT_H

#include <vector>
#include <string>
#include <classes/Expr/Expr.h>
#include "Stmt.h"

struct ForStmt: Stmt {
    const Ident* id;
    Expr *from;
    const bool incrUp;
    Expr *to;
    const std::vector<Stmt*>* stmts;

    ForStmt(Ident*, Expr*, bool, Expr*, std::vector<Stmt*>*);
    std::string toString() const override;
    void emitMips() override;
};


#endif //CPSL_COMPILER_FORSTMT_H
