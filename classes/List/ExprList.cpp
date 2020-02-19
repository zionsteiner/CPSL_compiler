//
// Created by zion on 2/18/20.
//

#include "ExprList.h"

ExprList::ExprList(Expr* expr) {
    list.push_back(expr);
}

void ExprList::append(Expr* expr) {
    list.push_back(expr);
}

void ExprList::toString() {
    for (std::vector<Expr*>::iterator expr = list.begin(); expr != list.end(); ++expr) {
        std::cout << expr.toString() << ' ';
    }
}