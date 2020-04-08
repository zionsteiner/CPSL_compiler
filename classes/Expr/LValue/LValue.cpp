//
// Created by zion on 2/23/20.
//

#include <globals.h>
#include <classes/Expr/ConstExpr/ConstExpr.h>
#include "LValue.h"

LValue::LValue(Ident* id, std::vector<Ext*>* exts): Expr(SIMPLE_T), id(id), exts(exts) {}
std::string LValue::toString() const {
    std::string retStr;
    retStr += id->toString();
    if (exts != nullptr) {
        for (auto ext = exts->begin(); ext != exts->end(); ++ext) {
            retStr += (*ext)->toString();
        }
    }

    return retStr;
}
Symbol* LValue::getSymbol() {
    Symbol* symbol = symbolTable.lookupSymbol(id->id);
    return symbol;
}

bool LValue::isCompVal() {
    auto symbol = symbolTable.lookupSymbol(id->id);
    if (symbol != nullptr) {
        auto expr = symbol->expr;
        if (expr != nullptr) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

// ToDo: figure out how to do UDT extensions
RegisterPool::Register LValue::emitMips() {
    auto symbol = symbolTable.lookupSymbol(id->id);
    auto reg = symbol->emitMips();

    return reg;
}
