//
// Created by zion on 2/23/20.
//


#include <classes/Expr/LValue/LValue.h>
#include <iostream>
#include <globals.h>
#include "SuccFunc.h"

SuccFunc::SuccFunc(Expr* expr): UnaryOpExpr(expr) {
    TypeEnum exprTypeEnum = expr->typeEnum;

    if (exprTypeEnum == SIMPLE_T) {
        auto lVal = dynamic_cast<LValue *>(expr);
        if (lVal != nullptr) {
            auto lValType = lVal->lookupType();
            exprTypeEnum = lValType->typeEnum;
        }
    }

    if (exprTypeEnum == INT_T) {
        this->typeEnum = INT_T;
    } else if (exprTypeEnum == BOOL_T) {
        this->typeEnum = BOOL_T;
    } else {
        throw "Error in PredFunc: expected either int or bool";
    }
}

Expr* SuccFunc::op(Expr* expr) {
   if (expr->isCompVal()) {
       auto expr_new = dynamic_cast<BoolConstExpr *>(expr);
       if (expr_new == nullptr) {
           auto expr_new = dynamic_cast<IntConstExpr *>(expr);
           if (expr_new == nullptr) {
               throw std::invalid_argument("Argument must be of type 'BoolConstExpr' or 'IntConstExpr'");
           } else {
               auto val = SuccFunc::op(expr_new->value);

               return new IntConstExpr(val);
           }
       } else {
           auto val = SuccFunc::op(expr_new->value);

           return new BoolConstExpr(val);
       }
   } else {
       return new SuccFunc(expr);
   }
}

bool SuccFunc::op(bool a) {
    return !a;
}

int SuccFunc::op(int a) {
    return ++a;
}

std::string SuccFunc::toString() const {
    return "succ(" + expr->toString() + ')';
}

RegisterPool::Register SuccFunc::emitMips() {
    auto exprReg = expr->emitMips();
    if (this->typeEnum == INT_T) {
        std::cout << "addi " + exprReg.getRegId() + ", " + exprReg.getRegId() + ", 1" << std::endl;

        return exprReg;
    } else if (this->typeEnum == BOOL_T) {
        auto testReg = registerPool.get();
        std::string label = symbolTable.getNextLabel();

        std::cout << "li " + testReg.getRegId() + ", 1" << std::endl;
        std::cout << "beq " + exprReg.getRegId() + ", " + testReg.getRegId() + ", " + label << std::endl;
        std::cout << "li " + exprReg.getRegId() + ", 1" << std::endl;
        std::cout << label + ":" << std::endl;
        std::cout << "li " + exprReg.getRegId() + ", 0" << std::endl;

        return exprReg;
    } else {
        throw std::invalid_argument("ERROR: invalid types in SuccFunc");
    }
}
