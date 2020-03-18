//
// Created by zion on 2/18/20.
//

#include "RecordType.h"

RecordType::RecordType(std::vector <VarAssign>* keys): keys(keys) {}
std::string toString() {
    std::string retStr = "record";
    for (auto key = keys->begin(); key != keys->end(); ++key) {
        retStr += ' ' + (*key)->toString();
    }
    retStr += " end";

    return retStr;
}