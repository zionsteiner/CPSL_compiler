//
// Created by zion on 2/20/20.
//

#include "Ident.h"

Ident::Ident(const char* id): id(id) {}
bool Ident::isCompVal() {return false;}
std::string Ident::toString() const {return id;}
