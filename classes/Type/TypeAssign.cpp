//
// Created by zion on 3/12/20.
//

#include <globals.h>
#include "TypeAssign.h"
#include "SimpleType.h"

TypeAssign::TypeAssign(Ident* id, Type* type): id(id) {
    auto s_type = dynamic_cast<SimpleType*>(type);
    if (s_type != nullptr) {
        this->type = symbolTable.lookupType(s_type->id->id);
    }
}
std::string TypeAssign::toString() const {return id->toString() + " = " + type->toString() + ';';}