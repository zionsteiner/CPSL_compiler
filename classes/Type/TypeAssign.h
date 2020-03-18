//
// Created by zion on 3/12/20.
//

#ifndef CPSL_COMPILER_TYPEASSIGN_H
#define CPSL_COMPILER_TYPEASSIGN_H


struct TypeAssign {
    const Ident* id;
    const Type* type;

    TypeAssign(Ident*, Type*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_TYPEASSIGN_H
