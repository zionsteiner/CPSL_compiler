//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_RECORDTYPE_H
#define CPSL_COMPILER_RECORDTYPE_H

#include <vector>
#include <map>
#include "Type.h"
#include "../Var/VarAssign.h"

struct RecordType: Type {
    const std::vector<VarAssign*>* keys;
    std::map<std::string, int> offsetMap;
    std::map<std::string, Type*> typeMap;
    int m_size = 0;
    explicit RecordType(std::vector<VarAssign *> *keys);
    int lookupOffset(std::string);
    Type* lookupType(std::string);
    std::string toString() const override;
    int size() override;
};


#endif //CPSL_COMPILER_RECORDTYPE_H
