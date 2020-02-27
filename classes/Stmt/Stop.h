//
// Created by zion on 2/25/20.
//

#ifndef CPSL_COMPILER_STOP_H
#define CPSL_COMPILER_STOP_H

#include "Stmt.h"

struct Stop: Stmt {
    std::string toString() const override;
};


#endif //CPSL_COMPILER_STOP_H
