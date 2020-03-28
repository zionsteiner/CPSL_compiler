//
// Created by zion on 2/26/20.
//

#ifndef CPSL_COMPILER_FORSTMT_H
#define CPSL_COMPILER_FORSTMT_H

#include <vector>
#include "Stmt.h"

struct ForStmt: Stmt {
    const Ident* id;
    const Expr* from;
    const std::string iterDirection;
    const Expr* to;
    const std::vector<Stmt*>* stmts;

    ForStmt(Ident*, Expr*, std::string, Expr*, std::vector<Stmt*>*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_FORSTMT_H
