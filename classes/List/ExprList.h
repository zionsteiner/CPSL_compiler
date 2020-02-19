//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_EXPRLIST_H
#define CPSL_COMPILER_EXPRLIST_H

#include "List.h"
#include "../Expr/Expr.h"

struct ExprList: List {
    std::vector<Expr*> list;

    ExprList(Expr*);
    void append(Expr*);
    void toString();
};


#endif //CPSL_COMPILER_EXPRLIST_H
