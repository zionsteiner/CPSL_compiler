//
// Created by zion on 2/23/20.
//

#include "LValue.h"

LValue::LValue(Ident* id, std::vector<Ext*>* exts): id(id), exts(exts) {}
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
bool LValue::isCompVal() {
    return false;
}
