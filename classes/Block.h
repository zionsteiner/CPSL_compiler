//
// Created by zion on 2/28/20.
//

#ifndef CPSL_COMPILER_BLOCK_H
#define CPSL_COMPILER_BLOCK_H

#include <vector>
#include <classes/Stmt/Stmt.h>

struct Block {
    const std::vector<Stmt*>* stmts;

    explicit Block(std::vector<Stmt*>*);
    std::string toString() const;
    void emitMips();
};


#endif //CPSL_COMPILER_BLOCK_H
