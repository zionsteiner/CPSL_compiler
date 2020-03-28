//
// Created by zion on 2/24/20.
//

#include "../Expr/Expr.h"
#include <vector>
#include "WriteStmt.h"

WriteStmt::WriteStmt(std::vector<Expr*>* args) : args(args) {}
std::string WriteStmt::toString() const {
    std::string retStr = "write(" + (*args)[0]->toString();
    for (auto arg = args->begin()+1; arg != args->end(); ++arg) {
        retStr += ", " + (*arg)->toString();
    }
    retStr += ')';

    return retStr;
}