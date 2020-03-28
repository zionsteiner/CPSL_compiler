//
// Created by zion on 2/26/20.
//

#include "../Expr/Ident.h"
#include "ForStmt.h"

ForStmt::ForStmt(Ident* id, Expr* from, std::string iterDir, Expr* to, std::vector<Stmt*>* stmtList):
    id(id), from(from), iterDirection(iterDirection), to(to), stmts(stmts) {}

std::string ForStmt::toString() const {
    std::string retStr = "for " + id->toString() + '=' + from->toString() + iterDirection + to->toString();
    for (auto stmt = stmts->begin(); stmt != stmts->end(); ++stmt) {
        retStr += (*stmt)->toString();
    }
    retStr += " end";
    return retStr;
}
