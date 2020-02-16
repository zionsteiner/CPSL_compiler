%{
#include <iostream>
#include <map>

typedef yy::parser::token token;

extern int yylex();
void yyerror(const char*);
%}

/* TODO: decide OO structure */
%union
{
int intVal;
char* id
char* chrVal;
char* strVal;

List* listPtr;
Const* constPtr;
Proc* procPtr;
Func* funcPtr;
Type* typePtr;
Record* recordPtr;
Array* recordPtr;
Var* varPtr;
Stmt* stmtPtr;
Expr* exprPtr;
}

%token ARRAY
%token BEGIN
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
%token PIPE
%token INV
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
%token ASSIGN
%token MOD
%token <int_val> OCTAL_CONST
%token <int_val> HEX_CONST
%token <int_val> INT_CONST
%token <chr_val> CHR_CONST
%token <str_val> STR_CONST
%token COMMENT

/* TODO: declare nonterminal types*/

%left BAR
%left AMP
%right INV
%nonassoc EQ NEQ LT LEQ GT GEQ
%left ADD SUB
%left MULT DIV MOD
%right UNARYMINUS

%%
/* TODO: re-add all optional nonterminals */
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

block: BEGIN statements END {}
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
    | return Stmt {}
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

returnStmt: RETURN expr {}
          | RETURN {}
          ;

readStmt: READ L_PAREN lValPlus R_PAREN {}
        ;

lValPlus: lValPlus COMMA lVal {}
        | lVal {}
        ;

writeStmt: WRITE L_PAREN exprPlus R_PAREN {}
         ;

exprPlus: exprPlus COMMA expr {}
        | expr {}
        ;

procCall: ID L_PAREN expr exprPlusOpt R_PAREN {}
        | ID L_PAREN R_PAREN {}
        ;

exprPlusOpt: exprPlus {}
           | {}
           ;

nullStmt: {}
        ;

/* 3.3 Expressions */
expr: expr BAR expr { $$ = Bar.bar($1, $3) }
    | expr AMP expr {}
    | expr EQ expr {}
    | expr NEQ expr {}
    | expr LEQ expr {}
    | expr GEQ expr {}
    | expr LT expr {}
    | expr GT expr {}
    | expr ADD expr { $$ = Add.Add($1, $3) }
    | expr SUB expr {}
    | expr MULT expr {}
    | expr DIV expr {}
    | expr MOD expr {}
    | INV expr {}
    | SUB expr %prec UNARYMINUS {}
    | L_PAREN expr R_PAREN {}
    | ID L_PAREN expr exprStar R_PAREN {}
    | ID L_PAREN R_PAREN {}
    | CHR L_PAREN expr R_PAREN {}
    | ORD L_PAREN expr R_PAREN {}
    | PRED L_PAREN expr R_PAREN {}
    | SUCC L_PAREN expr R_PAREN {}
    | lVal {}
    ;

lVal: ID dotOrIndexStar {}
    ;

dotOrIndexStar: dotOrIndexStar dotOrIndex {}
              | {}
              ;

dotOrIndex: PERIOD ID {}
          | L_BRACK expr R_BRACK {}
          ;
%%