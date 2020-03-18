%{
#include <iostream>
#include <map>
#include <vector>

#include "includes.h"

extern int yylex();
void yyerror(const char*);
%}

/* TODO: decide OO structure */
%union {
    int intVal;
    char chrVal;
    const char* strVal;
    bool boolVal;
    null nullVal;

    /* Nonterminal types */
    Program* programPtr;
    ConstDecl* constDeclPtr;
    ConstAssign* constAssignPtr;
    std::vector<ConstAssign>* constAssignListPtr;
    std::vector<Callable*>* callableListPtr;
    Procedure* procPtr;
    Function* funcPtr;
    Param* paramPtr;
    std::vector<Param*>* paramsPtr;
    Body* bodyPtr;
    Block* blockPtr;
    TypeDecl* typeDeclPtr;
    TypeAssign* typeAssignPtr;
    std::vector<TypeAssign>* typeAssignListPtr;
    Type* typePtr;
    SimpleType* simpleTypePtr;
    RecordType* recordTypePtr;
    ArrayType* arrayTypePtr;
    std::vector<Ident*>* idListPtr;
    VarDecl* varDeclPtr;
    VarAssign* varAssignPtr;
    std::vector<VarAssign*>* varAssignListPtr;
    Stmt* stmtPtr;
    std::vector<Stmt*>* stmtListPtr;
    AssnStmt* assnStmtPtr;
    IfStmt* ifStmtPtr;
    std::vector<ElseIfStmt*>* elseIfStmtListPtr;
    ElseIfStmt* elseIfStmtPtr;
    ElseStmt* elseStmtPtr;
    WhileStmt* whileStmtPtr;
    RepeatStmt* repeatStmtPtr;
    ForStmt* forStmtPtr;
    StopStmt* stopStmtPtr;
    ReturnStmt* returnStmtPtr;
    ReadStmt* readStmtPtr;
    LValue* lvalPtr;
    std::vector<LValue*>* lValListPtr;
    WriteStmt* writeStmtPtr;
    Expr* exprPtr;
    std::vector<Expr*> exprListPtr;
    ProcCall* procCallPtr;
    std::vector<Ext*>* extListPtr;
    Ext* extPtr;
    Dot* dotPtr;
    Index* indexPtr;
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
%type <programPtr> Program
%type <constDeclPtr> ConstDeclOpt
%type <constDeclPtr> ConstDecl
%type <constAssignListPtr> ConstAssignPlus
%type <constAssignPtr> ConstAssign
%type <callableListPtr> procOrFuncStar
%type <procPtr> procDecl
%type <funcPtr> funcDecl
%type <paramsPtr> paramsOpt
%type <paramsPtr> params
%type <paramPtr> param
%type <boolVal> varOrRefOpt
%type <bodyPtr> body
%type <blockPtr> block
%type <typeDecl> typeDeclOpt
%type <typeDecl> typeDecl
%type <typeAssignListPtr> typeAssignPlus
%type <typeAssignPtr> typeAssign
%type <typePtr> type
%type <simpleTypePtr> simpleType
%type <recordTypePtr> recordType
%type <varAssignListPtr> varAssignStar
%type <arrayTypePtr> arrayType
%type <idListPtr> idList
%type <varDeclPtr> varDeclOpt
%type <varDecl> varDecl
%type <varAssignListPtr> varAssignPlus
%type <varAssignPtr> varAssign
%type <stmtListPtr> stmts
%type <stmtPtr> stmt
%type <assnStmtPtr> assnStmt
%type <ifStmtPtr> ifStmt
%type <elseIfStmtPtr> elseIfStmtOpt
%type <elseIfStmtListPtr> elseIfStmts
%type <elseIfStmtPtr> elseIfStmt
%type <elseStmtPtr> elseStmtOpt
%type <whileStmtPtr> whileStmt
%type <repeatStmtPtr> repeatStmt
%type <forStmtPtr> forStmt
%type <stopStmtPtr> stopStmt
%type <returnStmtPtr> returnStmt
%type <readStmtPtr> readStmt
%type <lValListPtr> lValPlus
%type <writeStmtPtr> writeStmt
%type <exprListPtr> exprPlus
%type <procCallPtr> procCall
%type <exprListPtr> exprPlusOpt
%type <nullVal> nullStmt
%type <exprPtr> expr
%type <lValPtr> lVal
%type <extListPtr> dotOrIndexPlusOpt
%type <extListPtr> dotOrIndexPlus
%type <extPtr> dotOrIndex
%type <extPtr> dot
%type <extPtr> index


%left BAR
%left AMP
%right NOT
%nonassoc EQ NEQ LT LEQ GT GEQ
%left ADD SUB
%left MULT DIV MOD
%right UNARYMINUS

%%
/* CPSL Declarations */
program: constDeclOpt typeDeclOpt varDeclOpt procOrFuncStar block PERIOD {$$ = new Program($1, $2, $3, $4, $5);}

/* 3.1.1 Constant Rules */
constDeclOpt: constDecl {$$ = $1;}
             | {$$ = nullptr;}
             ;

constDecl: CONST constAssignPlus {$$ = new ConstDecl($2);}
         ;

constAssignPlus: constAssignPlus constAssign {$1->push_back($2); $$ = $1;}
               | constAssign {$$ = new vector<ConstAssign*>(); $$->push_back($1);}
               ;

/* TODO: Add to symbol table */
constAssign: ID EQ expr SEMICOLON {$$ = new ConstAssign($1, $3);}
           ;

/* 3.1.2 Procedure and Function Rules */
procOrFuncStar: procOrFuncStar procDecl {$$ = $1; $$->push_back($2);}
              | procOrFuncStar funcDecl {$$ = $1; $$->push_back($2);}
              | {$$ = new std::vector<Callable*>();}
              ;

procDecl: PROCEDURE ID L_PAREN paramsOpt R_PAREN SEMICOLON FORWARD SEMICOLON {}
        | PROCEDURE ID L_PAREN paramsOpt R_PAREN SEMICOLON body SEMICOLON {}

/* ToDo: different classes for forward declaration and definition? */
funcDecl: FUNCTION ID L_PAREN paramsOpt R_PAREN COLON type SEMICOLON FORWARD SEMICOLON {$$ = new Function($2, $4, $7);}
        | FUNCTION ID L_PAREN paramsOpt R_PAREN COLON type SEMICOLON body SEMICOLON {$$ = new Function($2, $4, $7, $9);}
        ;

paramsOpt: params {$$ = $1;}
         | {$$ = nullptr;}
         ;

params: params SEMICOLON param {$$ = $1; $$->push_back($3);}
      | param {$$ = new std::vector<Param*>(); $$->push_back($1);}
      ;

param: varOrRefOpt idList COLON type {$$ = new Param($1, $2, $4);}
     ;

varOrRefOpt: VAR {$$ = true;}
           | REF {$$ = false;}
           | {$$ = true;}
           ;

body: constDeclOpt typeDeclOpt varDeclOpt block {$$ = new Body($1, $2, $3, $4);}
    ;

block: BEGIN_TKN stmts END {$$ = new Block($2);}
     ;

/* 3.1.3 Type Rules */
typeDeclOpt: typeDecl {$$ = $1;}
            | {$$ = nullptr;}
            ;

typeDecl: TYPE typeAssignPlus {$$ = new TypeDecl($2);}
        ;

typeAssignPlus: typeAssignPlus typeAssign {$$ = $1; $$->push_back($2);}
              | typeAssign {$$ = new std::vector<TypeAssign*>(); $$->push_back($1);}
              ;

typeAssign: ID EQ type SEMICOLON {$$ = new TypeAssign($1, $3);}
          ;

type: simpleType {$$ = $1;}
    | recordType {$$ = $1;}
    | arrayType {$$ = $1;}
    ;

simpleType: ID {$$ = SimpleType($1);}
          ;

recordType: RECORD varAssignStar END {$$ = new RecordType($2);}
          ;

// ToDo: does bison automatically do left recursion removal and factorization?
varAssignStar: varAssignStar varAssign {$$->push_back($2);}
             | {$$ = new std::vector<VarAssign*>();}
             ;

arrayType: ARRAY L_BRACK expr COLON expr R_BRACK OF type {$$ = new ArrayType($3, $5, $7);}
         ;

idList: idList COMMA ID {$1->push_back($3); $$ = $1;}
      | ID {$$ = new std::vector<Ident*>(); $$->push_back($1);}
      ;

/* 3.1.4 Variable Rules */
varDeclOpt: varDecl {$$ = $1;}
           | {$$ = nullptr;}
           ;

varDecl: VAR varAssignPlus {$$ = new VarDecl($2);}
       ;

varAssignPlus: varAssignPlus varAssign {$1->push_back($2); $$ = $1;}
             | varAssign {$$ = new std::vector<VarAssign*>(); $$->push_back($1);}
             ;

varAssign: idList COLON type SEMICOLON {$$ = new VarAssign($1, $3);}
         ;

/* 3.2 CPSL Statements */
stmts: stmts SEMICOLON stmt {$1->push_back($3); $$ = $1;}
     | stmt {$$ = new std::vector<Stmt*>(); $$->push_back($1);}
     ;

stmt: assnStmt {$$ = $1;}
    | ifStmt {$$ = $1;}
    | whileStmt {$$ = $1;}
    | repeatStmt {$$ = $1;}
    | forStmt {$$ = $1;}
    | stopStmt {$$ = $1;}
    | returnStmt {$$ = $1;}
    | readStmt {$$ = $1;}
    | writeStmt {$$ = $1;}
    | procCall {$$ = $1;}
    | nullStmt {$$ = $1;}
    ;

assnStmt: lVal ASSIGN expr {$$ = new AssnStmt($1, $3);}
        ;

ifStmt: IF expr THEN stmts elseIfStmtsOpt elseStmtOpt END {$$ = new IfStmt($2, $4, $5, $6);}
      ;

elseIfStmtsOpt: elseIfStmts {$$ = $1;}
              | {$$ = nullptr;}
              ;

elseIfStmts: elseIfStmts elseIfStmt {$1->append($1); $$ = $1;}
           | elseIfStmt {$$ = new ElseIfStmtList($1);}
           ;

elseIfStmt: ELSEIF expr THEN stmts {$$ = new ElseIfStmt($2, $4);}
          ;

elseStmtOpt: ELSE stmts {$$ = new ElseStmt($2);}
           | {$$ = nullptr;}
           ;

whileStmt: WHILE expr DO stmts END {$$ = new WhileStmt($2, $4);}
         ;

repeatStmt: REPEAT stmts UNTIL expr {$$ = new RepeatStmt($2, $4);}
          ;

forStmt: FOR ID ASSIGN expr TO expr DO stmts END {$$ = new ForStmt($2, $4, "to", $6, $8);}
       | FOR ID ASSIGN expr DOWNTO expr DO stmts END {$$ = new ForStmt($2, $4, "downto", $6, $8);}
       ;

stopStmt: STOP {$$ = new Stop();}
        ;

returnStmt: RETURN expr {$$ = new ReturnStmt($2);}
          | RETURN {$$ = new ReturnStmt(nullptr);}
          ;

readStmt: READ L_PAREN lValPlus R_PAREN {$$ = new ReadStmt($3);}
        ;

lValPlus: lValPlus COMMA lVal {$1->append($3); $$ = $1;}
        | lVal {$$ = new std::vector<LValue*>($1);}
        ;

writeStmt: WRITE L_PAREN exprPlus R_PAREN {$$ = new WriteStmt($3);}
         ;

exprPlus: exprPlus COMMA expr {$1->append($3); $$ = $1;}
        | expr {$$ = new std::vector<Expr*>(); $$->push_back($1);}
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
    | PRED L_PAREN expr R_PAREN {$$ = PredFunc::op($3);}
    | SUCC L_PAREN expr R_PAREN {$$ = SuccFunc::op($3);}
    | lVal {$$ = $1;}
    | INT_CONST {$$ = new IntConst($1);}
    | CHR_CONST {$$ = new ChrConst($1);}
    | STR_CONST {$$ = new StrConst($1);}
    | ID {$$ = new Ident($1);}
    ;

lVal: ID dotOrIndexPlusOpt {$$ = new LValue($1, $2);}
    ;

dotOrIndexPlusOpt: dotOrIndexPlus {$$ = $1;}
                 | {$$ = nullptr;}
                 ;

dotOrIndexPlus: dotOrIndexPlus dotOrIndex {$1->append($2); $$ = $1;}
              | dotOrIndex {$$ = new vector<Ext*>(); $$->push_back($1);}
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