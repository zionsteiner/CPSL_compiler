//
// Created by zion on 2/24/20.
//

#ifndef CPSL_COMPILER_READSTMT_H
#define CPSL_COMPILER_READSTMT_H

#include <string>
#include <List/ExprList.h>
#include "Stmt.h"

struct ReadStmt: Stmt {
    const ExprList<LValue*>* lValList;

    explicit ReadStmt(ExprList<LValue*>*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_READSTMT_H
