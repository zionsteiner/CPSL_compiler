//
// Created by zion on 2/28/20.
//

#ifndef CPSL_COMPILER_BODY_H
#define CPSL_COMPILER_BODY_H

struct Body {
    const ConstDecl* constDecl;
    const TypeDecl* typeDecl;
    const VarDecl* varDecl;
    const Block* block;

    Body(ConstDecl*, TypeDecl*, VarDecl*, Block*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_BODY_H
