//
// Created by zion on 2/19/20.
//

#ifndef CPSL_COMPILER_PARAM_H
#define CPSL_COMPILER_PARAM_H


struct Param {
    const bool isPassByRef;
    const std::vector<Ident*>* idList;
    const Type* type;

    Param(bool, std::vector<Ident*>*, Type*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_PARAM_H
