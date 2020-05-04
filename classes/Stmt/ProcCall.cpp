//
// Created by zion on 2/24/20.
//

#include <globals.h>
#include <classes/Expr/LValue/LValue.h>
#include <classes/Callable/Procedure.h>
#include "ProcCall.h"

ProcCall::ProcCall(Ident* id, std::vector<Expr*>* args): id(id), args(args) {}
std::string ProcCall::toString() const {
    std::string retStr;
    if (args == nullptr) {
        retStr += id->toString() + "()";
    } else {
        retStr += id->toString() + '(';
        for (auto arg = args->begin(); arg != args->end(); ++arg) {
            retStr += (*arg)->toString();
        }
        retStr += ')';

        return retStr;
    }

    return retStr;
}

void ProcCall::emitMips() {
    // Generate callable signature
    std::string sig = id->id + "(";
    for (auto arg : *args) {
        auto lVal = dynamic_cast<LValue*>(arg);
        if (lVal != nullptr) {
            sig += " " + std::to_string(lVal->lookupType()->typeEnum);
        } else {
            sig += " " + std::to_string(arg->typeEnum);
        }
    }
    sig += ")";

    // Lookup callable
    auto callable = symbolTable.lookupCallable(sig);
    auto proc = dynamic_cast<Procedure*>(callable);
    if (proc == nullptr) {
        throw std::invalid_argument("Procedure with sig " + sig + " not found in symbol table");
    }

    symbolTable.saveState();

    // Load params
    int argN = 0;
    for (auto param : *proc->params) {
        for (auto argId : *param->idList) {
            Expr* arg = (*args)[argN];
            symbolTable.loadArg(argId->id, arg, param);
            argN++;
        }
    }

    symbolTable.enterScope();


    // Call function
    std::cout << "jal " + proc->label << std::endl;
    if (!proc->isEmitted()) {
        proc->emitMips();
    }

    symbolTable.exitScope();
}