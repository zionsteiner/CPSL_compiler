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

void ConstDecl::emitMips() {
    for (auto constAssign = constAssignList->begin(); constAssign != constAssignList->end(); ++constAssign) {
        // Identify and lookup type of expr
        auto expr = (*constAssign)->expr;
        Symbol* constSymbol = nullptr;

        while (true) {
            const auto i_expr = dynamic_cast<const IntConstExpr *>(expr);
            if (i_expr != nullptr) {
                auto type = symbolTable.lookupType("integer");
                constSymbol = new Symbol(i_expr, type);
                break;
            }
            const auto c_expr = dynamic_cast<const ChrConstExpr *>(expr);
            if (c_expr != nullptr) {
                auto type = symbolTable.lookupType("char");
                constSymbol = new Symbol(c_expr, type);
                break;
            }
            const auto s_expr = dynamic_cast<const StrConstExpr *>(expr);
            if (s_expr != nullptr) {
                auto type = symbolTable.lookupType("string");
                constSymbol = new Symbol(s_expr, type);
                break;
            }
            const auto b_expr = dynamic_cast<const BoolConstExpr *>(expr);
            if (b_expr != nullptr) {
                auto type = symbolTable.lookupType("boolean");
                constSymbol = new Symbol(b_expr, type);
                break;
            }
            const auto symbol = dynamic_cast<LValue*>(expr)->getSymbol();
            if (symbol != nullptr) {
                expr = symbol->expr;
            }
        }


        if (constSymbol == nullptr) {
            throw std::runtime_error("Something weird happened.");
        } else {
            symbolTable.addSymbol((*constAssign)->id->id, constSymbol);
        }
    }
}