//
// Created by zion on 3/9/20.
//

#ifndef CPSL_COMPILER_CONSTDECL_H
#define CPSL_COMPILER_CONSTDECL_H


struct ConstDecl {
    const std::vector<ConstAssign*>* constAssignList;

    explicit ConstDecl(std::vector<ConstAssign*>*);
    std::string toString() const;
};


#endif //CPSL_COMPILER_CONSTDECL_H
