//
// Created by zion on 3/28/20.
//

#include "SymbolTable.h"

LValue* SymbolTable::lookupLVal(std::string id) {
    for (auto level = scopeLevels.rbegin(); level != scopeLevels.rend(); ++level) {
        auto lVal = level->lookupLVal(id);
        if (lVal != nullptr) {
            return lVal;
        } else {
            return nullptr;
        }
    }
}

Type* SymbolTable::lookupType(std::string id) {
    for (auto level = scopeLevels.rbegin(); level != scopeLevels.rend(); ++level) {
        auto type = level->lookupType(id);
        if (type != nullptr) {
            return type;
        } else {
            return nullptr;
        }
    }
}