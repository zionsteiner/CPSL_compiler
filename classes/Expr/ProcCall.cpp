//
// Created by zion on 2/24/20.
//

#include "ProcCall.h"

ProcCall::ProcCall(Ident* id, ExprList* args): id(id), args(args) {}
bool ProcCall::isCompVal() {return false;}
std::string ProcCall::toString() const {
    std::string retStr;
    if (args == nullptr) {
        retStr += id->toString() + "()";
    } else {
        retStr += id->toString() + '(' + args->toString() + ')';
    }

    return retStr;
}