//
// Created by zion on 2/14/20.
//

#ifndef CPSL_COMPILER_TYPE_H
#define CPSL_COMPILER_TYPE_H

#include <string>
// ToDo: use shared pointers to control type instance ownership
enum TypeEnum {INT_T, CHR_T, STR_T, BOOL_T, ARRAY_T, RECORD_T, SIMPLE_T};
struct Type {
    TypeEnum typeEnum;

    Type(TypeEnum typeEnum) : typeEnum(typeEnum) {}
    virtual int size() = 0;
    virtual std::string toString() const = 0;
    virtual ~Type() {};
};

#endif //CPSL_COMPILER_TYPE_H