//
// Created by zion on 2/24/20.
//

#ifndef CPSL_COMPILER_EXPRLIST_H
#define CPSL_COMPILER_EXPRLIST_H

#include <vector>
#include "List.h"

template <typename T>
struct ExprList: List {
    std::vector<T*> list;

    explicit ExprList(T*);
    void append(T*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_EXPRLIST_H
