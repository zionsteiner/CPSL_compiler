//
// Created by zion on 2/19/20.
//

#include "VarAssignList.h"

VarAssignList::VarAssignList(VarAssign* varAssn) {
    list.push_back(varAssn);
}
void VarAssignList::append(VarAssign* varAssn) {
    list.push_back(varAssn);
}
std::string VarAssignList::toString() const {
    std::string str;
    for (auto i : list) {
        str += i->toString();
    }

    return str;
}