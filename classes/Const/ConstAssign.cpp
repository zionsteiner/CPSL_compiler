//
// Created by zion on 2/28/20.
//

#include <stdexcept>
#include <Symbol.h>
#include <classes/Expr/ConstExpr/IntConstExpr.h>
#include <globals.h>
#include <classes/Expr/ConstExpr/ChrConstExpr.h>
#include <classes/Expr/ConstExpr/StrConstExpr.h>
#include <classes/Expr/ConstExpr/BoolConstExpr.h>
#include <classes/Expr/LValue/LValue.h>
#include "ConstAssign.h"

ConstAssign::ConstAssign(Ident* id, Expr* expr): id(id), expr(expr) {}
std::string ConstAssign::toString() const {
    return  id->toString() + " = " + expr->toString() + ';';
}

void ConstAssign::emitMips() {
    if (!expr->isCompVal()) {
        throw std::invalid_argument("ERROR: Non-compile value used in CONST assignment");
    }

    // Identify and lookup type of expr
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
        // Runs through while loop again if this is the case (should be changed to switch stmt using TypeEnum)
        const auto symbol = dynamic_cast<LValue*>(expr)->getSymbol();
        if (symbol != nullptr) {
            expr = symbol->expr;
        }
    }

    if (constSymbol == nullptr) {
        throw std::runtime_error("Something weird happened.");
    } else {
        symbolTable.addSymbol(id->id, constSymbol);
    }
}