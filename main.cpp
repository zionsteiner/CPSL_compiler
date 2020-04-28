//
// Created by zion on 2/21/20.
//

#include <globals.h>

extern int yyparse();
int line = 1;
int token = 1;
RegisterPool registerPool;
SymbolTable symbolTable;

int main() {
    yyparse();
}