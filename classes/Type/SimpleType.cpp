//
// Created by zion on 4/11/20.
//

#include "SimpleType.h"
#include "globals.h"

std::string SimpleType::toString() const {
    return id->id;
}

SimpleType::SimpleType(Ident* id): Type(SIMPLE_T), id(id) {
    auto type = symbolTable.lookupType(id->id);
    if (type != nullptr) {
        this->typeEnum = type->typeEnum;
    }
}

int SimpleType::size() {
    auto t_type = symbolTable.lookupType(id->id);
    if (t_type != nullptr) {
        return t_type->size();
    } else {
        return 0;
    }
}

Type * SimpleType::lookupType() {
    Type* type = symbolTable.lookupType(id->id);

    return type;
}

// ToDo: figure out how to replace simpletype with lookup

