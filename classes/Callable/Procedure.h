//
// Created by zion on 3/9/20.
//

#ifndef CPSL_COMPILER_PROCEDURE_H
#define CPSL_COMPILER_PROCEDURE_H

#include "Callable.h"

struct Procedure: Callable {
    const Ident* id;
    const std::vector<Param*>* params;
    const bool forward;
    const Body* body;

    // Forward decl constructor
    Function::Function(Ident*, std::vector<Param*>*, bool);

    // Definition constructor
    Function(Ident*, std::vector<Param*>*, Body*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_PROCEDURE_H
