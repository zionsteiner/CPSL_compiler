//
// Created by zion on 2/24/20.
//

#include "ProcCall.h"

ProcCall::ProcCall(Ident* id, std::vector<Expr*>* args): id(id), args(args) {}
std::string ProcCall::toString() const {
    std::string retStr;
    if (args == nullptr) {
        retStr += id->toString() + "()";
    } else {
        retStr += id->toString() + '(';
        for (auto arg = args->begin(); arg != args->end(); ++arg) {
            retStr += (*arg)->toString();
        }
        retStr += ')';

        return retStr;
    }

    return retStr;
}