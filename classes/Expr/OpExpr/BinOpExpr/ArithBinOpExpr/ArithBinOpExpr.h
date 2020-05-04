//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_ARITHBINOPEXPR_H
#define CPSL_COMPILER_ARITHBINOPEXPR_H

#include <classes/Expr/ConstExpr/IntConstExpr.h>
#include <classes/Type/SimpleType.h>
#include <classes/Expr/LValue/LValue.h>
#include <stdexcept>
#include "../BinOpExpr.h"

struct ArithBinOpExpr: BinOpExpr {
    ArithBinOpExpr(Expr*, Expr*);

    template<typename T>
    static Expr* binOp(Expr* a, Expr* b) {
        return  new T(a, b);
    }
//        // If a is lval, use lval's expression instead
//        auto aLVal = dynamic_cast<LValue*>(a);
//        if (aLVal != nullptr) {
//            a = aLVal->getSymbol()->expr;
//            if (a == nullptr) {
//                a = aLVal;
//            }
//        }
//
//        auto bLVal = dynamic_cast<LValue*>(b);
//        if (bLVal != nullptr) {
//            b = bLVal->getSymbol()->expr;
//            if (b == nullptr) {
//                b = bLVal;
//            }
//        }
//
//        if (a->isCompVal() && b->isCompVal()) {
//            auto a_new = dynamic_cast<IntConstExpr*> (a);
//            auto b_new = dynamic_cast<IntConstExpr*> (b);
//            auto val = T::binOp(a_new->value, b_new->value);
//
//            return new IntConstExpr(val);
//        } else {
//            return new T(a, b);
//        }
//    }
};


#endif //CPSL_COMPILER_ARITHBINOPEXPR_H
