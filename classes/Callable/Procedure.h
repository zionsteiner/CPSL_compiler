//
// Created by zion on 3/9/20.
//

#ifndef CPSL_COMPILER_PROCEDURE_H
#define CPSL_COMPILER_PROCEDURE_H

#include <vector>
#include "Callable.h"
#include "../Expr/Ident.h"
#include "../Param.h"
#include "../Body.h"

struct Procedure: Callable {
    // Forward decl constructor
    Procedure(Ident*, std::vector<Param*>*);

    // Definition constructor
    Procedure(Ident*, std::vector<Param*>*, Body*);
    std::string toString() const override;
    void emitMips() override;
};


#endif //CPSL_COMPILER_PROCEDURE_H
