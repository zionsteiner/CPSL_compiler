//
// Created by zion on 2/28/20.
//

#ifndef CPSL_COMPILER_CONSTASSIGN_H
#define CPSL_COMPILER_CONSTASSIGN_H


struct ConstAssign {
    const Ident* id;
    const Expr* expr;

    ConstAssign(Ident*, Expr*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_CONSTASSIGN_H
