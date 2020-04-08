//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_RECORDTYPE_H
#define CPSL_COMPILER_RECORDTYPE_H

#include <vector>
#include "Type.h"
#include "../Var/VarAssign.h"

struct RecordType: Type {
    const std::vector<VarAssign*>* keys;
    explicit RecordType(std::vector<VarAssign *> *keys);
    std::string toString() const override;
    int size() override;
};


#endif //CPSL_COMPILER_RECORDTYPE_H
