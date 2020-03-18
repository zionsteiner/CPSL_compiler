//
// Created by zion on 3/9/20.
//

#ifndef CPSL_COMPILER_FUNCTION_H
#define CPSL_COMPILER_FUNCTION_H

#include "Callable.h"

struct Function: Callable {
    const Ident* id;
    const std::vector<Param*>* params;
    const Type* type;
    const bool forward;
    const Body* body;

    // Forward decl constructor
    Function::Function(Ident*, std::vector<Param*>*, Type*);

    // Definition constructor
    Function(Ident*, std::vector<Param*>*, Type*, Body*);
    std::string toString() const override;
};


#endif //CPSL_COMPILER_FUNCTION_H
