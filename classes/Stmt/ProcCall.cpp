//
// Created by zion on 2/24/20.
//

#include <globals.h>
#include <classes/Expr/LValue/LValue.h>
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
        auto lVal = dynamic_cast<LValue *>(arg);
        if (lVal != nullptr) {
            sig += " " + std::to_string(lVal->lookupType()->typeEnum);
        } else {
            sig += " " + std::to_string(arg->typeEnum);
        }
    }
    sig += ")";

    // Lookup callable
    auto callable = symbolTable.lookupCallable(sig);
    if (callable == nullptr) {
        throw std::invalid_argument("Callable with sig " + sig + " not found in symbol table");
    }

    // Save local regs
    int currOffset = 0;
    int regSpillOffset = 4 * (registerPool.getUsedRegs().size() + 2);
    std::cout << "addi $sp, $sp, -" + std::to_string(regSpillOffset) << std::endl;

    auto usedRegs = registerPool.getUsedRegs();
    for (auto reg = usedRegs.begin(); reg != usedRegs.end(); ++reg) {
        std::cout << "sw " + *reg + ", " + std::to_string(currOffset) + "($sp)" << std::endl;
        currOffset += 4;
    }
    // Save $ra and $fp
    std::cout << "sw $ra, " + std::to_string(currOffset) + "($sp)" << std::endl;
    currOffset += 4;
    std::cout << "sw $fp, " + std::to_string(currOffset) + "($sp)" << std::endl;

    // Move function args to stack
    int funcScopeOffset = 0;
    std::cout << "sw $sp, $sp, -" + std::to_string(funcScopeOffset);
    symbolTable.enterScope("$sp");
    for (auto param : *callable->params) {
        if (!param->isPassByRef) {
            for (auto id: *param->idList) {
                int nextOffset = symbolTable.getNextOffset();
                Symbol* symbol = new Symbol(nextOffset, param->type);
                symbolTable.addSymbol(id->id, symbol);
            }
        }
    }

    // Get label
    std::cout << "jal " + callable->label << std::endl;

    // Epilog
    std::cout << "addi $sp, $sp, " + std::to_string(funcScopeOffset) << std::endl;
    std::cout << "lw $fp, " + std::to_string(currOffset) + "($sp)" << std::endl;
    currOffset -= 4;
    std::cout << "lw $ra, " + std::to_string(currOffset) + "($sp)" << std::endl;

    for (auto reg = usedRegs.rbegin(); reg != usedRegs.rend(); ++reg) {
        currOffset -= 4;
        std::cout << "lw " + *reg + ", " + std::to_string(currOffset) + "($sp)" << std::endl;
    }

    std::cout << "addi $sp, $sp, " + std::to_string(regSpillOffset) << std::endl;
}