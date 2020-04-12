//
// Created by zion on 3/9/20.
//

#include <iostream>
#include <classes/Expr/ConstExpr/IntConstExpr.h>
#include <classes/Expr/ConstExpr/ChrConstExpr.h>
#include <classes/Expr/ConstExpr/StrConstExpr.h>
#include <classes/Expr/ConstExpr/BoolConstExpr.h>
#include "globals.h"
#include "ConstDecl.h"

ConstDecl::ConstDecl(std::vector<ConstAssign*>* constAssignList): constAssignList(constAssignList) {}
std::string ConstDecl::toString() const {
    std::string retStr = "CONST";
    for (auto constAssign = constAssignList->begin(); constAssign != constAssignList->end(); ++constAssign) {
        retStr += "\n\t" + (*constAssign)->toString();
    }

    return retStr;
}

void ConstDecl::emitMips() {}