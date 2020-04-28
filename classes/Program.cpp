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
    // Output MIPS code for functions
    for (auto callable : *callableList) {
        callable->emitMips();
    }

    std::cout << "\t.text\n.globl main\nmain:" << std::endl;
    if (constDecl != nullptr) {constDecl->emitMips();}
    if (typeDecl != nullptr) {typeDecl->emitMips();}
    if (varDecl != nullptr) {varDecl->emitMips();}

    block->emitMips();

    std::cout << "# Exit" << std::endl;
    std::cout << "li $v0, 10" << std::endl;
    std::cout << "syscall" << std::endl;

    // Emit string constants
    std::cout << "\t.data\n" << std::endl;
    auto strings = symbolTable.getStrings();
    for (auto str = strings->begin(); str != strings->end(); ++str) {
        std::cout << str->first << ": .asciiz " << "\"" << str->second << "\"" << std::endl;
    }
}
