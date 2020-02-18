//
// Created by zion on 2/17/20.
//

#ifndef CPSL_COMPILER_STRCONST_H
#define CPSL_COMPILER_STRCONST_H


class StrConst: Const {
    const std::string value;
    StrConst(value);
    void toString();
};


#endif //CPSL_COMPILER_STRCONST_H
