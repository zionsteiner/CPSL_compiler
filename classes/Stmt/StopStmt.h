//
// Created by zion on 2/25/20.
//

#ifndef CPSL_COMPILER_STOPSTMT_H
#define CPSL_COMPILER_STOPSTMT_H

#include <string>
#include "Stmt.h"

struct StopStmt: Stmt {
    std::string toString() const override;
};


#endif //CPSL_COMPILER_STOPSTMT_H
