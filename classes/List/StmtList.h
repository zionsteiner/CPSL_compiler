//
// Created by zion on 2/26/20.
//

#ifndef CPSL_COMPILER_STMTLIST_H
#define CPSL_COMPILER_STMTLIST_H

#include <vector>
#include <Stmt/Stmt.h>
#include "List.h"

struct StmtList: List {
    std::vector<Stmt*> list;

    explicit StmtList(Stmt*);
    void append(Stmt*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_STMTLIST_H
