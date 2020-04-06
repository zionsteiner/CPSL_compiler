//
// Created by zion on 3/9/20.
//

#ifndef CPSL_COMPILER_PROGRAM_H
#define CPSL_COMPILER_PROGRAM_H

#include "Block.h"
#include <vector>
#include <string>
#include <classes/Const/ConstDecl.h>
#include <classes/Type/TypeDecl.h>
#include <classes/Var/VarDecl.h>
#include <classes/Callable/Callable.h>

struct Program {
    ConstDecl *constDecl;
    TypeDecl *typeDecl;
    const VarDecl* varDecl;
    const std::vector<Callable*>* callableList;
    const Block* block;

    Program(ConstDecl*, TypeDecl*, VarDecl*, std::vector<Callable*>*, Block*);

    Program(const TypeDecl *typeDecl);

    std::string toString() const;
    void emitMips();
};


#endif //CPSL_COMPILER_PROGRAM_H
