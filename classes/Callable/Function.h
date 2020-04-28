//
// Created by zion on 3/9/20.
//

#ifndef CPSL_COMPILER_FUNCTION_H
#define CPSL_COMPILER_FUNCTION_H

#include <vector>
#include "Callable.h"
#include "../Expr/Ident.h"
#include "../Param.h"
#include "../Body.h"

struct Function: Callable {
    const Type* type;

    // Forward decl constructor
    Function(Ident*, std::vector<Param*>*, Type*);

    // Definition constructor
    Function(Ident*, std::vector<Param*>*, Type*, Body*);

    std::string toString() const override;
    void emitMips() override;
};


#endif //CPSL_COMPILER_FUNCTION_H
