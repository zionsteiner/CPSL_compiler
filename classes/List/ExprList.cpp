//
// Created by zion on 2/24/20.
//

#include <Expr/Expr.h>
#include "ExprList.h"

template <typename T>
ExprList<T>::ExprList(T* a) {
    list.push_back(a);
}

template <typename T>
void ExprList<T>::append(T* a) {
    list.push_back(a);
}

template <typename T>
std::string ExprList<T>::toString() const {
    std::string retStr = list[0]->toString();
    if (list.size() > 1) {
        for (auto expr = list.begin() + 1; expr != list.end(); ++expr) {
            retStr += ", " + (*expr)->toString();
        }
    }

    return retStr;
}