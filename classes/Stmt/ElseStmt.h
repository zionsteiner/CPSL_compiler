//
// Created by zion on 2/26/20.
//

#ifndef CPSL_COMPILER_ELSESTMT_H
#define CPSL_COMPILER_ELSESTMT_H

#include <vector>
#include "Stmt.h"

struct ElseStmt: Stmt {
    const std::vector<Stmt*>* stmts;

    ElseStmt(std::vector<Stmt*>*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_ELSESTMT_H
