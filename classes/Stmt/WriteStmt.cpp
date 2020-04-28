//
// Created by zion on 2/24/20.
//

#include "../Expr/Expr.h"
#include <vector>
#include <globals.h>
#include <iostream>
#include <classes/Expr/ConstExpr/ConstExpr.h>
#include <classes/Expr/LValue/LValue.h>
#include "WriteStmt.h"

WriteStmt::WriteStmt(std::vector<Expr*>* args) : args(args) {}
std::string WriteStmt::toString() const {
    std::string retStr = "write(" + (*args)[0]->toString();
    for (auto arg = args->begin()+1; arg != args->end(); ++arg) {
        retStr += ", " + (*arg)->toString();
    }
    retStr += ')';

    return retStr;
}

void WriteStmt::emitMips() {
    for (auto arg = args->begin(); arg != args->end(); ++arg) {
        TypeEnum argType = (*arg)->typeEnum;

        RegisterPool::Register reg;
        bool flag = true;
        while (flag) {
            switch (argType) {
                case INT_T:
                case BOOL_T: {
                    std::cout << "# Write INT OR BOOL" << std::endl;
                    std::cout << "li $v0, 1" << std::endl;
                    reg = (*arg)->emitMips();
                    std::cout << "move $a0, " + reg.getRegId() << std::endl;
                    std::cout << "syscall" << std::endl;

                    flag = false;

                    break;
                }
                case CHR_T: {
                    std::cout << "# Write CHR" << std::endl;
                    std::cout << "li $v0, 11" << std::endl;
                    reg = (*arg)->emitMips();
                    std::cout << "move $a0, " + reg.getRegId() << std::endl;
                    std::cout << "syscall" << std::endl;

                    flag = false;

                    break;
                }
                case STR_T: {
                    std::cout << "# Write STR" << std::endl;
                    std::cout << "li $v0, 4" << std::endl;
                    reg = (*arg)->emitMips();
                    std::cout << "la $a0, (" + reg.getRegId() + ")" << std::endl;
                    std::cout << "syscall" << std::endl;

                    flag = false;

                    break;
                }
                case SIMPLE_T: {
                    auto lval = dynamic_cast<LValue*>((*arg));
                    if (lval == nullptr) {
                        throw std::invalid_argument("Expected lval, got something else in WRITE");
                    }
                    argType = lval->lookupType()->typeEnum;

                    break;
                }
                default: {
                    throw std::invalid_argument("ERROR: Cannot write type");
                }
            }
        }
    }
}