//
// Created by zion on 2/25/20.
//

#include <iostream>
#include "StopStmt.h"

std::string StopStmt::toString() const {return "stop";}

void StopStmt::emitMips() {
    std::cout << "# Exit" << std::endl;
    std::cout << "li $v0, 10" << std::endl;
    std::cout << "syscall" << std::endl;
}
