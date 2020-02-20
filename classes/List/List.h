//
// Created by zion on 2/18/20.
//

#ifndef CPSL_COMPILER_LIST_H
#define CPSL_COMPILER_LIST_H


struct List {
    virtual void append();
    virtual std::string toString() const;
};


#endif //CPSL_COMPILER_LIST_H
