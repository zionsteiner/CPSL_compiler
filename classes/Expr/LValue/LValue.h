//
// Created by zion on 2/23/20.
//

#ifndef CPSL_COMPILER_LVALUE_H
#define CPSL_COMPILER_LVALUE_H

#include <vector>
#include <RegisterPool.h>
#include <classes/Type/Type.h>
#include <Symbol.h>
#include "Ext.h"
#include "../Expr.h"
#include "../Ident.h"

struct LValue: Expr {
    const Ident* id;
    const std::vector<Ext*>* exts;

    LValue(Ident*, std::vector<Ext*> *exts);

    std::string toString() const override;
    bool isCompVal() override;
    Symbol* getSymbol();
    RegisterPool::Register emitMips() override;
};


#endif //CPSL_COMPILER_LVALUE_H
