//
// Created by zion on 2/18/20.
//

#include "RecordType.h"

RecordType::RecordType(std::vector<VarAssign *> *keys) : Type(RECORD_T), keys(keys) {}

std::string RecordType::toString() const {
    std::string retStr = "record";
    for (auto key = keys->begin(); key != keys->end(); ++key) {
        retStr += ' ' + (*key)->toString();
    }
    retStr += " end";

    return retStr;
}

int RecordType::size() {return 0;}