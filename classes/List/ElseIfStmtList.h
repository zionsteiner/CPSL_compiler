//
// Created by zion on 2/27/20.
//

#ifndef CPSL_COMPILER_ELSEIFSTMTLIST_H
#define CPSL_COMPILER_ELSEIFSTMTLIST_H

#include <Stmt/ElseIfStmt.h>
#include "List.h"

struct ElseIfStmtList: List {
    std::vector<ElseIfStmt*> list;

    explicit ElseIfStmtList(ElseIfStmt*);
    void append(ElseIfStmt*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_ELSEIFSTMTLIST_H
