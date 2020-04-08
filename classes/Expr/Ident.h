//
// Created by zion on 2/20/20.
//

#ifndef CPSL_COMPILER_IDENT_H
#define CPSL_COMPILER_IDENT_H


#include <string>

struct Ident {
    const std::string id;

    Ident(const char*);
    bool isCompVal();
    std::string toString() const;
};


#endif //CPSL_COMPILER_IDENT_H
