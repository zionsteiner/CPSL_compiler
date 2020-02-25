%{
#include <iostream>
#include <map>
#include <vector>

#include "classes/Expr/Expr.h"
#include "classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/ArithBinOpExpr.h"
#include "classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Add.h"
#include "classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Div.h"
#include "classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Mod.h"
#include "classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Mult.h"
#include "classes/Expr/OpExpr/BinOpExpr/ArithBinOpExpr/Sub.h"
#include "classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/BoolBinOpExpr.h"
#include "classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/Amp.h"
#include "classes/Expr/OpExpr/BinOpExpr/BoolBinOpExpr/Bar.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/CmprBinOpExpr.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/EQ.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/NEQ.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/LEQ.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/GEQ.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/LT.h"
#include "classes/Expr/OpExpr/BinOpExpr/CmprBinOpExpr/GT.h"
#include "classes/Expr/OpExpr/UnaryOpExpr/Not.h"
#include "classes/Expr/OpExpr/UnaryOpExpr/UnaryMinus.h"
#include "classes/Expr/ProcCall.h"
#include "classes/Stmt/Stmt.h"
#include "classes/Stmt/WriteStmt.h"
#include "classes/Stmt/ReadStmt.h"
#include "classes/Stmt/ReturnStmt.h"

extern int yylex();
void yyerror(const char*);
%}

/* TODO: decide OO structure */
%union
{
int intVal;
char* id;
char chrVal;
char* strVal;

Expr* exprPtr;
List* listPtr;
ProcCall* procCallPtr;

}

%token ARRAY
%token BEGIN_TKN
%token CHR
%token CONST
%token DO
%token DOWNTO
%token ELSE
%token ELSEIF
%token END
%token FOR
%token FORWARD
%token FUNCTION
%token IF
%token OF
%token ORD
%token PRED
%token PROCEDURE
%token READ
%token RECORD
%token REF
%token REPEAT
%token RETURN
%token STOP
%token SUCC
%token THEN
%token TO
%token TYPE
%token UNTIL
%token VAR
%token WHILE
%token WRITE
%token <id> ID
%token ADD
%token SUB
%token MULT
%token DIV
%token AMP
%token BAR
%token NOT
%token EQ
%token NEQ
%token LT
%token LEQ
%token GT
%token GEQ
%token PERIOD
%token COMMA
%token SEMICOLON
%token COLON
%token L_PAREN
%token R_PAREN
%token L_BRACK
%token R_BRACK
%token ASSIGN
%token MOD
%token <intVal> INT_CONST
%token <chrVal> CHR_CONST
%token <strVal> STR_CONST
%token COMMENT

/* TODO: declare nonterminal types*/
%type <exprPtr> expr;
%type <listPtr> exprPlus;
%type <listPtr> dotOrIndexPlus;
%type <procCallPtr> procCallPtr;

%left BAR
%left AMP
%right NOT
%nonassoc EQ NEQ LT LEQ GT GEQ
%left ADD SUB
%left MULT DIV MOD
%right UNARYMINUS

%%
/* CPSL Declarations */
program: constDeclOpt typeDeclOpt varDeclOpt procOrFuncStar block PERIOD {}

/* 3.1.1 Constant Rules */
constDeclOpt: constDecl {}
             | {}
             ;

constDecl: CONST constAssignPlus {}
         ;

constAssignPlus: constAssignPlus constAssign {}
               | constAssign {}
               ;

/* TODO: Add to symbol table */
constAssign: ID EQ expr SEMICOLON {}
           ;

/* 3.1.2 Procedure and Function Rules */
procOrFuncStar: procOrFuncStar procDecl {}
              | procOrFuncStar funcDecl {}
              | {}
              ;

procDecl: PROCEDURE ID L_PAREN paramsOpt R_PAREN SEMICOLON FORWARD SEMICOLON {}
        | PROCEDURE ID L_PAREN paramsOpt R_PAREN SEMICOLON body SEMICOLON {}

funcDecl: FUNCTION ID L_PAREN paramsOpt R_PAREN COLON type SEMICOLON FORWARD {}
        | FUNCTION ID L_PAREN paramsOpt R_PAREN COLON type SEMICOLON body SEMICOLON {}
        ;

paramsOpt: params {}
         | {}
         ;

params: params SEMICOLON param {}
      | param {}
      ;

param: varOrRefOpt idList COLON type {}
     ;

varOrRefOpt: VAR {}
           | REF {}
           | {}
           ;

body: constDeclOpt typeDeclOpt varDeclOpt block {}
    ;

block: BEGIN_TKN stmts END {}
     ;

/* 3.1.3 Type Rules */
typeDeclOpt: typeDecl {}
            | {}
            ;

typeDecl: TYPE typeAssignPlus {}
        ;

typeAssignPlus: typeAssignPlus typeAssign {}
              | typeAssign {}
              ;

typeAssign: ID EQ type SEMICOLON {}
          ;

type: simpleType {}
    | recordType {}
    | arrayType {}
    ;

simpleType: ID {}
          ;

recordType: RECORD varAssignStar END {}
          ;

varAssignStar: varAssignStar varAssign {}
             | {}
             ;

arrayType: ARRAY L_BRACK expr COLON expr R_BRACK OF type {}
         ;

idList: idList COMMA ID {}
      | ID {}
      ;

/* 3.1.4 Variable Rules */
varDeclOpt: varDecl {}
           | {}
           ;

varDecl: VAR varAssignPlus {}
       ;

varAssignPlus: varAssignPlus varAssign {}
             | varAssign {}
             ;

varAssign: idList COLON type SEMICOLON {}
         ;

/* 3.2 CPSL Statements */
stmts: stmts COLON stmt {}
     | stmt {}
     ;

stmt: assnStmt {}
    | ifStmt {}
    | whileStmt {}
    | repeatStmt {}
    | forStmt {}
    | stopStmt {}
    | returnStmt {}
    | readStmt {}
    | writeStmt {}
    | procCall {}
    | nullStmt {}
    ;

assnStmt: lVal ASSIGN expr {}
        ;

ifStmt: IF expr THEN stmts elseIfStmtStar elseStmtOpt END {}
      ;

elseIfStmtStar: elseIfStmtStar elseIfStmt {}
              | {}
              ;

elseIfStmt: ELSEIF expr THEN stmts {}
          ;

elseStmtOpt: ELSE stmts {}
           | {}
           ;

whileStmt: WHILE expr DO stmts END {}
         ;

repeatStmt: REPEAT stmts UNTIL expr {}
          ;

forStmt: FOR ID ASSIGN expr toOrDownto expr DO stmts END {}
       ;

toOrDownto: TO {}
          | DOWNTO {}
          ;

stopStmt: STOP {}
        ;

returnStmt: RETURN expr {$$ = new ReturnStmt($2);}
          | RETURN {$$ = new ReturnStmt(nullptr);}
          ;

readStmt: READ L_PAREN lValPlus R_PAREN {$$ = new ReadStmt($3);}
        ;

lValPlus: lValPlus COMMA lVal {$1->append($3); $$ = $1;}
        | lVal {$$ = new lValList($1);}
        ;

writeStmt: WRITE L_PAREN exprPlus R_PAREN {$$ = new WriteStmt($3);}
         ;

exprPlus: exprPlus COMMA expr {$1->append($3); $$ = $1;}
        | expr {$$ = new ExprList<Expr*>($1);}
        ;

procCall: ID L_PAREN exprPlusOpt R_PAREN {$$ = new ProcCall($1, $3);}
        ;

exprPlusOpt: exprPlus {$$ = $1;}
           | {$$ = nullptr;}
           ;

nullStmt: {$$ = nullptr;}
        ;

/* 3.3 Expressions */
expr: expr BAR expr {$$ = BoolBinOpExpr::binOp<Bar>($1, $3);}
    | expr AMP expr {$$ = BoolBinOpExpr::binOp<Amp>($1, $3);}
    | expr EQ expr {$$ = CmprBinOpExpr::binOp<EQ>($1, $3);}
    | expr NEQ expr {$$ = CmprBinOpExpr::binOp<NEQ>($1, $3);}
    | expr LEQ expr {$$ = CmprBinOpExpr::binOp<LEQ>($1, $3);}
    | expr GEQ expr {$$ = CmprBinOpExpr::binOp<GEQ>($1, $3);}
    | expr LT expr {$$ = CmprBinOpExpr::binOp<LT>($1, $3);}
    | expr GT expr {$$ = CmprBinOpExpr::binOp<GT>($1, $3);}
    | expr ADD expr {$$ = ArithOpExpr::binOp<Add>($1, $3);}
    | expr SUB expr {$$ = ArithOpExpr::binOp<Sub>($1, $3);}
    | expr MULT expr {$$ = ArithOpExpr::binOp<Mult>($1, $3);}
    | expr DIV expr {$$ = ArithOpExpr::binOp<Div>($1, $3);}
    | expr MOD expr {$$ = ArithOpExpr::binOp<Mod>($1, $3);}
    | NOT expr {$$ = Not::op($2);}
    | SUB expr %prec UNARYMINUS {$$ = UnaryMinus::op($2);}
    | L_PAREN expr R_PAREN {$$ = $2;}
    | procCall {}
    | CHR L_PAREN expr R_PAREN {$$ = ChrFunc::op($3);}
    | ORD L_PAREN expr R_PAREN {$$ = OrdFunc::op($3);}
    | PRED L_PAREN expr R_PAREN {$$
    = PredFunc::op($3);}
    | SUCC L_PAREN expr R_PAREN {$$ = SuccFunc::op($3);}
    | lVal {$$ = $1;}
    | INT_CONST {$$ = new IntConst($1);}
    | CHR_CONST {$$ = new ChrConst($1);}
    | STR_CONST {$$ = new StrConst($1);}
    | ID {$$ = new Ident($1);}
    ;

lVal: ID dotOrIndexPlus {$$ = new LValue($1, $2);}
    ;

dotOrIndexPlus: dotOrIndexPlus dotOrIndex {$1->append($2); $$ = $1;}
              | dotOrIndex {$$ = new DotOrIndexPlus($1);}
              ;

dotOrIndex: dot {$$ = $1;}
          | index {$$ = $1;}
          ;

dot: PERIOD ID {$$ = new DotExt($2);}
   ;

index: L_BRACK expr R_BRACK {$$ = new IndexExt($2);}
     ;
%%

void yyerror(const char* err) {
    std::cerr << err << std::endl;
}