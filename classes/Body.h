//
// Created by zion on 2/28/20.
//

#ifndef CPSL_COMPILER_BODY_H
#define CPSL_COMPILER_BODY_H

#include <classes/Type/TypeDecl.h>
#include <classes/Var/VarDecl.h>
#include <classes/Const/ConstDecl.h>
#include <classes/Block.h>

struct Body {
    ConstDecl* constDecl;
    TypeDecl* typeDecl;
    VarDecl* varDecl;
    Block* block;

    Body(ConstDecl*, TypeDecl*, VarDecl*, Block*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_BODY_H
