//
// Created by zion on 2/10/20.
//

#include "Const.h"

bool Const::isCompVal() { return true; }
int Const::isCompVal() { return value; }
void Const::print() { std::cout << value; }

Const::Const( int value ): value( value ) {};