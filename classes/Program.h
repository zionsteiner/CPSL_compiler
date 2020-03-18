//
// Created by zion on 3/9/20.
//

#ifndef CPSL_COMPILER_PROGRAM_H
#define CPSL_COMPILER_PROGRAM_H


#include <Const/ConstDecl.h>
#include <Type/TypeDecl.h>
#include <Var/VarDecl.h>
#include <Callable/Callable.h>
#include "Block.h"
#include <vector>
#include <string>

struct Program {
    const ConstDecl* constDecl;
    const TypeDecl* typeDecl;
    const VarDecl* varDecl;
    const std::vector<Callable*>* callableList;
    const Block* block;

    Program(ConstDecl*, TypeDecl*, VarDecl*, std::vector<Callable*>*, Block*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_PROGRAM_H
