//
// Created by zion on 2/26/20.
//

#include <Expr/Ident.h>
#include "ForStmt.h"

ForStmt::ForStmt(Ident* id, Expr* from, std::string iterDir, Expr* to, StmtList* stmtList):
    id(id), from(from), iterDirection(iterDirection), to(to), stmts(stmts) {}

std::string ForStmt::toString() const {
    return "for " + id->toString() + '=' + from->toString() + iterDirection + to->toString() + stmts->toString() + "end";
}
