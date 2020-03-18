//
// Created by zion on 2/14/20.
//

#ifndef CPSL_COMPILER_TYPE_H
#define CPSL_COMPILER_TYPE_H


struct Type {
    // ToDo: how to define this for different types?
    // virtual int size();
    virtual std::string toString() const;
};


#endif //CPSL_COMPILER_TYPE_H
