//
// Created by zion on 2/28/20.
//

#include "Body.h"

Body::Body(ConstDecl* constDecl, TypeDecl* typeDecl, VarDecl* varDecl, Block* block):
constDecl(constDecl), typeDecl(typeDecl), varDecl(varDecl), block(block) {}

std::string Body::toString() const {
    std::string retStr;
    if (constDecl != nullptr) {
        retStr += constDecl->toString();
    }
    if (typeDecl != nullptr) {
        retStr += typeDecl->toString();
    }
    if (varDecl != nullptr) {
        retStr += varDecl->toString();
    }
    retStr += block->toString();

    return retStr;
}