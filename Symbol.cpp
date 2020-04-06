//
// Created by zion on 4/6/20.
//

#include "Symbol.h"

Symbol::Symbol(Expr* expr, Type* type) {
    this->expr = expr;
    this->offset = -1;
    this->type = type;
}
Symbol::Symbol(int offset) {
    this->offset = offset;
    this->expr = nullptr;
    this->type = type;
}

Symbol::Symbol(const Expr* expr, Type* type) {
    this->expr = const_cast<Expr *>(expr);
    this->offset = -1;
    this->type = type;
}
