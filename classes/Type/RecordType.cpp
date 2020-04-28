//
// Created by zion on 2/18/20.
//

#include <globals.h>
#include "RecordType.h"
#include "SimpleType.h"

RecordType::RecordType(std::vector<VarAssign*>* keys) : Type(RECORD_T), keys(keys) {}

std::string RecordType::toString() const {
    std::string retStr = "record";
    for (auto key = keys->begin(); key != keys->end(); ++key) {
        retStr += ' ' + (*key)->toString();
    }
    retStr += " end";

    return retStr;
}

int RecordType::size() {
    return m_size;
}

int RecordType::lookupOffset(std::string id) {
    return offsetMap[id];
}

Type* RecordType::lookupType(std::string id) {
    auto type = typeMap[id];

    auto s_type = dynamic_cast<SimpleType*>(type);
    if (s_type != nullptr) {
        type = symbolTable.lookupType(s_type->id->id);
    }

    return type;
}

void RecordType::emitMips() {
    int currOffset = 0;
    for (auto key = keys->begin(); key != keys->end(); ++key) {
        auto idList = (*key)->idList;
        auto type = (*key)->type;

        for (auto id: *idList) {
            offsetMap[id->id] = currOffset;
            currOffset += type->size();

            typeMap[id->id] = type;
        }

        m_size += idList->size() * type->size();
    }
}
