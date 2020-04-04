//
// Created by zion on 3/9/20.
//

#include <globals.h>
#include "Program.h"

Program::Program(ConstDecl* constDecl, TypeDecl* typeDecl, VarDecl* varDecl, std::vector<Callable*>* callableList, Block* block)
: constDecl(constDecl), typeDecl(typeDecl), varDecl(varDecl), callableList(callableList), block(block)
{}

std::string Program::toString() const {
    std::string retStr;

    if (constDecl != nullptr) {retStr += constDecl->toString() + '\n';}
    if (typeDecl != nullptr) {retStr += typeDecl->toString() + '\n';}
    if (varDecl != nullptr) {retStr += varDecl->toString() + '\n';}
    for (auto callable = callableList->begin(); callable != callableList->end(); ++callable) {
        retStr += (*callable)->toString() + '\n';
    }
    retStr += block->toString();
    retStr += '.';

    return retStr;
}

void Program::emitMips() {
    SymbolTable symbolTable;
    RegisterPool registerPool;

    std::cout << "\t.text\nmain:\n";


}
