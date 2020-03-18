//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_RECORDTYPE_H
#define CPSL_COMPILER_RECORDTYPE_H

#include "Type.h"

struct RecordType: Type {
    const std::vector<VarAssign>* keys;

    RecordType(std::vector<VarAssign>*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_RECORDTYPE_H
