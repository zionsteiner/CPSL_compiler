//
// Created by zion on 3/9/20.
//

#ifndef CPSL_COMPILER_CALLABLE_H
#define CPSL_COMPILER_CALLABLE_H

#include <string>
#include <classes/Param.h>
#include <classes/Body.h>
#include <classes/Type/SimpleType.h>

struct Callable {
    const Ident* id;
    std::vector<Param*>* params;
    bool forward;
    Body* body;

    bool emitted = false;
    std::string label;

    virtual std::string toString() const = 0;
    virtual void emitMips() = 0;
    bool isEmitted();

    Callable(Ident* id, std::vector<Param*>* params);

    Callable(Ident* id, std::vector<Param*>* params, Body* body);
    virtual ~Callable();
};

#endif //CPSL_COMPILER_CALLABLE_H