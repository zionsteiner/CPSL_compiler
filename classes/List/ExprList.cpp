//
// Created by zion on 2/18/20.
//

#include <vector>
#include <iostream>
#include "ExprList.h"

ExprList::ExprList(Expr* expr) {
    list.push_back(expr);
}

void ExprList::append(Expr* expr) {
    list.push_back(expr);
}

void ExprList::toString() {
    std::cout << list[0];
    for (std::vector<Expr*>::iterator expr = list.begin() + 1; expr != list.end(); ++expr) {
        std::cout << ', ' + expr.toString();
    }
}