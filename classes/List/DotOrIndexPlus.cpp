//
// Created by zion on 2/23/20.
//

#include "DotOrIndexPlus.h"

DotOrIndexPlus::DotOrIndexPlus(Ext* ext) {
    list.push_back(ext);
};
void DotOrIndexPlus::append(Ext* ext) {
    list.push_back(ext);
}
std::string DotOrIndexPlus::toString() const {
    std::string str;
    for (auto ext = list.begin(); ext != list.end(); ++ext) {
        str += (*ext)->toString();
    }
}