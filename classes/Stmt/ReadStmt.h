//
// Created by zion on 2/24/20.
//

#ifndef CPSL_COMPILER_READSTMT_H
#define CPSL_COMPILER_READSTMT_H

#include <string>
#include "Stmt.h"

struct ReadStmt: Stmt {
    const std::vector<LValue*>* lValList;

    explicit ReadStmt(std::vector<LValue*>*);
    std::string toString() const override;
    void emitMips();
};


#endif //CPSL_COMPILER_READSTMT_H
