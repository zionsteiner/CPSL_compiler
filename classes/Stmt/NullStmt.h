//
// Created by zion on 4/8/20.
//

#ifndef CPSL_COMPILER_NULLSTMT_H
#define CPSL_COMPILER_NULLSTMT_H


#include <string>
#include "Stmt.h"

struct NullStmt: Stmt {
    std::string toString() const override;
    void emitMips() override;
};


#endif //CPSL_COMPILER_NULLSTMT_H
