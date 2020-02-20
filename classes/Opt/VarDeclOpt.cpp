//
// Created by zion on 2/20/20.
//

#include "VarDeclOpt.h"

VarDeclOpt::VarDeclOpt() {_isEmtpy = true;}
VarDeclOpt::VarDeclOpt(VarDecl* varDecl): varDecl(varDecl) {_isEmtpy = false;}
std::string VarDeclOpt::toString() const {
    if (_isEmtpy) {
        return "";
    } else {
        return varDecl->toString();
    }
}